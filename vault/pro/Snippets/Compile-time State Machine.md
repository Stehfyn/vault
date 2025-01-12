

























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































utputEvent, typename TerminatingEvent, std::size_t... Is, typename Tuple>
constexpr auto generate_event_sequence_transitions_with_terminator(std::index_sequence<Is...>, const Tuple& guards) {
    using namespace sml;
    return sml::make_transition_table(
        // Some initial meta-event will initialize the event sequence listening
        (*sml::state<state_name<0>> + sml::event<InitialEvent> = sml::state<state_name<1>>),

        // State + guarded transition on each predicated event in sequence... 
        (sml::state<state_name<Is + 1>> + sml::event<kernel_event>[std::get<Is>(guards)] = sml::state<state_name<Is + 2>>)...,

        // If we complete the event sequence, generate our meta-OutputEvent and move to a final state
        sml::state<state_name<sizeof...(Is) + 1>> / sml::process(OutputEvent{}) = sml::state<state_name<sizeof...(Is) + 2>>,

        // Another event sequence may produce our bound OutputEvent first, therefore reset the sequence if another sequence beat this one
        (sml::state<state_name<Is + 1>> + sml::event<OutputEvent> = sml::state<state_name<0>>)...,

        // Early event sequence reset in the case of some meta-TerminatingEvent (like a shutdown event)
        (sml::state<state_name<Is + 1>> + sml::event<TerminatingEvent> = sml::state<state_name<0>>)...,

        // Basic transition logger
        (sml::state<state_name<Is + 1>> + sml::on_entry<_> / []{ std::cout << "[internal]: entered sub-state " << std::to_string(Is) << std::endl; })...,
        
        // After producing our OutputEvent, receive it immediately back, then return to the initial state to wait on another InitialEvent
        sml::state<state_name<sizeof...(Is) + 2>> + sml::event<OutputEvent> = sml::state<state_name<0>>
    );
}

template <typename InitialEvent, typename OutputEvent, typename... EventPredicates>
constexpr auto make_event_sequence(const std::tuple<EventPredicates...>& epreds) {
    return generate_event_sequence_transitions<InitialEvent, OutputEvent>(std::make_index_sequence<sizeof...(EventPredicates)>{}, epreds);
}

template <typename InitialEvent, typename OutputEvent, typename TerminatingEvent, typename... EventPredicates>
constexpr auto make_event_sequence_with_terminator(const std::tuple<EventPredicates...>& epreds) {
    return generate_event_sequence_transitions_with_terminator<InitialEvent, OutputEvent, TerminatingEvent>(std::make_index_sequence<sizeof...(EventPredicates)>{}, epreds);
}

// Internal state machine meta-events
struct launch_started{};
struct launch_completed{};
struct mcc_terminated{};
struct match_loading_started{};
struct match_started{};

// Workaround to having to define the same transition multiple times for sub-machines at the top level
// This appears to be a constraint sml has in dealing HSM's (Hierarchical state machines)
// Original issue: https://github.com/boost-ext/sml/issues/185
// Repo created in response: https://github.com/erikzenker/hsm
struct dummy_event{
    dummy_event() { throw std::runtime_error("dummy_events should never be constructed!"); }
};

// Pseudo Event Predicates (Queries kernel_events about their properties)
constexpr auto is_mcc_launcher_start = [](const auto& kevent) { 
    return kevent.record.msg == "mcc_launcher_start";
};

constexpr auto is_mcc_start = [](const auto& kevent) { 
    return kevent.record.msg == "mcc_start";
};

constexpr auto is_mcc_terminate = [](const auto& kevent) { 
    return kevent.record.msg == "mcc_terminate";
};

constexpr auto is_loading_gfx = [](const auto& kevent) { 
    return kevent.record.msg == "loading_gfx";
};

constexpr auto is_h1_match_file_create = [](const auto& kevent) { 
    return kevent.record.msg == "is_h1_match_file_create";
};

constexpr auto is_h1_initial_sound_file_read = [](const auto& kevent) { 
    return kevent.record.msg == "is_h1_initial_sound_file_read";
};

// In boost::sml terms, this is a nested, composite state machine with orthogonal regions,
// where the state machine itself can defer/process kernel_events, and generate internal events.
template <class = class Dummy>
class controller {
    
  public:

    template <typename event_type>
    void process_event(const event_type& event_) {
        sm_.process_event(event_);
    }

    // Since mcc is the top-level state machine, can just use is()
    template <typename... Args>
    bool mcc_is(const Args&... args) {
        return sm_.is(args...);
    }

    // However, since user is a sub-state machine, we have to decompose it from mcc to query it on its own
    template <typename... Args>
    bool user_is(const Args&... args) {
        return sm_.template is<decltype(sml::state<user>)>(args...);
    }

  private:

    struct user {

        // The equivalent of a sequence of predicates, modeled as a sub-state machine of the user state
        struct sub1 {
            static constexpr auto guards = std::make_tuple(
                is_h1_match_file_create,
                is_h1_initial_sound_file_read
            );
            constexpr auto operator()() const {
                return make_event_sequence<match_loading_started, match_started>(guards);
            }
        };

        // The top-level user state machine
        constexpr auto operator()() const {
            using namespace sml;
            return make_transition_table(
                *"offline"_s + sml::event<launch_started> = "waiting_on_launch"_s,
                "waiting_on_launch"_s + sml::event<launch_completed> = "in_menus"_s,
                "in_menus"_s + sml::event<mcc_terminated> = "offline"_s,
                "in_menus"_s + sml::event<kernel_event> [is_loading_gfx] / sml::process(match_loading_started{}) = "loading_in"_s,
                "loading_in"_s + sml::event<match_started> = "in_match"_s,
                "in_match"_s + sml::event<mcc_terminated> = "offline"_s,

                // Creates a fully encapsulated orthogonal region out of sub-state by providing an unused termination edge
                *sml::state<sub1> + sml::event<dummy_event> = X,

                "offline"_s + sml::on_entry<_> / []{std::cout << "[user]: offline\n"; },
                "waiting_on_launch"_s + sml::on_entry<_> / []{std::cout << "[user]: waiting_on_launch\n"; },
                "in_menus"_s + sml::on_entry<_> / []{std::cout << "[user]: in_menus\n"; },
                "loading_in"_s + sml::on_entry<_> / []{std::cout << "[user]: loading_in\n"; },
                "in_match"_s + sml::on_entry<_> / []{std::cout << "[user]: in_match\n"; }
            );
        }
    };

    // The highest level machine modeling the game process, the user, tbd...
    struct mcc {
        constexpr auto operator()() const {
            using namespace sml;
            return make_transition_table(
                *"off"_s + sml::event<kernel_event> [is_mcc_launcher_start] / sml::process(launch_started{}) = "launching"_s,
                "launching"_s + sml::event<kernel_event> [is_mcc_start] / sml::process(launch_completed{}) = "on"_s,
                "on"_s + sml::event<kernel_event> [is_mcc_terminate] / sml::process(mcc_terminated{}) = "off"_s,

                // Creates a fully encapsulated orthogonal region out of user-state by providing an unused termination edge
                *sml::state<user> + sml::event<dummy_event> = X,

                "off"_s + sml::on_entry<_> / []{std::cout << "[mcc]: off\n"; },
                "launching"_s + sml::on_entry<_> / []{std::cout << "[mcc]: launching\n"; },
                "on"_s + sml::on_entry<_> / []{std::cout << "[mcc]: on\n"; }
            );
        }
    };

  private:

    sml::sm<mcc, sml::process_queue<std::queue>> sm_{};
};

int main() {
    using namespace boost::sml;

    controller<> sm{};

    assert(sm.mcc_is("off"_s));
    assert(sm.user_is("offline"_s));

    sm.process_event(
        kernel_event{
            EVENT_RECORD{
                "mcc_launcher_start"
            },
            g_trace_context
        }
    );

    assert(sm.mcc_is("launching"_s));
    assert(sm.user_is("waiting_on_launch"_s));

    sm.process_event(
        kernel_event{
            EVENT_RECORD{
                "mcc_start"
            },
            g_trace_context
        }
    );

    assert(sm.mcc_is("on"_s));
    assert(sm.user_is("in_menus"_s));

    sm.process_event(
        kernel_event{
            EVENT_RECORD{
                "loading_gfx"
            },
            g_trace_context
        }
    );

    assert(sm.mcc_is("on"_s));
    assert(sm.user_is("loading_in"_s));

    sm.process_event(
        kernel_event{
            EVENT_RECORD{
                "is_h1_match_file_create"
            },
            g_trace_context
        }
    );

    assert(sm.mcc_is("on"_s));
    assert(sm.user_is("loading_in"_s));

    sm.process_event(
        kernel_event{
            EVENT_RECORD{
                "is_h1_initial_sound_file_read"
            },
            g_trace_context
        }
    );

    assert(sm.mcc_is("on"_s));
    assert(sm.user_is("in_match"_s));

    sm.process_event(
        kernel_event{
            EVENT_RECORD{
                "mcc_terminate"
            },
            g_trace_context
        }
    );

    assert(sm.mcc_is("off"_s));
    assert(sm.user_is("offline"_s));
}
```

