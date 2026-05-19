<!-- generated-from-dump2 -->
# Causatum — Stochastic Event-Stream Generator

Clojure library for generating *streams of events* from stochastic state machines — you describe a graph of states, edges have probabilities and (optionally) latency distributions, and the library emits a lazy sequence of `{:state ... :t ...}` events sampling paths through the graph. Niche but elegant for simulation workloads where you need plausible-looking input data: synthetic user behaviour for load testing, fault-injection traces, mock telemetry. Stuart Halloway / Cognitect orbit (the author has Cognitect-adjacent talks). Worth filing under "stochastic-process modeling" rather than "state machines" — the latter implies deterministic transitions, which causatum explicitly is not.

```clojure
(require '[causatum.event-streams :as es])

(def model
  {:graph    {:idle    [[:working 0.7] [:idle 0.3]]
              :working [[:idle    0.6] [:failed 0.1] [:working 0.3]]
              :failed  [[:idle    1.0]]}
   :delay    {:default [:constant 1]}})

(take 10
  (es/event-stream model [{:state :idle :t 0}]))
;; => ({:state :idle :t 0}
;;     {:state :working :t 1}
;;     {:state :working :t 2}
;;     {:state :idle    :t 3} ...)
```

## References
- <https://github.com/candera/causatum>
