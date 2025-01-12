







































































![[Pasted image 20250111173043.png]]![](https://github.com/Stehfyn/vault/blob/main/vault/media/Pasted%20image%2020250111173043.png)


![[Pasted image 20250111173541.png]]![](https://github.com/Stehfyn/vault/blob/main/vault/media/Pasted%20image%2020250111173541.png)







































































![[Pasted image 20250111173043.png]]![](https://github.com/Stehfyn/vault/blob/main/vault/media/Pasted%20image%2020250111173043.png)

![[Pasted image 20250111173541.png]]![](https://github.com/Stehfyn/vault/blob/main/vault/media/Pasted%20image%2020250111173541.png)





























































![[Pasted image 20250111173043.png]]![](https://github.com/Stehfyn/vault/blob/main/vault/media/Pasted%20image%2020250111173043.png)
![[Pasted image 20250111173541.png]]![](https://github.com/Stehfyn/vault/blob/main/vault/media/Pasted%20image%2020250111173541.png)





















































![[Pasted image 20250111173043.png]]![](https://github.com/Stehfyn/vault/blob/main/vault/media/Pasted%20image%2020250111173043.png)
![[Pasted image 20250111173541.png]]![](https://github.com/Stehfyn/vault/blob/main/vault/media/Pasted%20image%2020250111173541.png)















































![[Pasted image 20250111173043.png]]![](https://github.com/Stehfyn/vault/blob/main/vault/media/Pasted%20image%2020250111173043.png)
![[Pasted image 20250111173541.png]]![](https://github.com/Stehfyn/vault/blob/main/vault/media/Pasted%20image%2020250111173541.png)







o solve an uncomputable problem, you need an uncomputable oracle, which means you go from the 0th Turing degree (where computable problems live) to the first Turing degree. (PS: There are an infinite number of Turing degrees.) We describe problems that cannot be solved in polynomial time as "infeasible". Uncomputable problems are vastly harder than infeasible, they are beyond brain-melting hard, cosmically hard. They are the hardest problems except for themselves, the famous Halting Problem being the canonical example.

The next limit is feasibility, which has already been mentioned. By convention, computer scientists speak of P (the class of problems solvable in polynomial time) as the class of "feasible" problems. A problem is feasible if it is possible that it could realistically be solved or usefully approximated. Problems requiring exponential time (and beyond) are generally treated as infeasible. There is provably an infinite hierarchy of harder and harder infeasible yet computable problems that require exponential time, or more. Note that all of these problems are still "easy" compared to the uncomputable problems mentioned in the previous paragraph!

The next set of limits come from physics -- see Wiki's page on the physical limits of computation.

The next limit is what I have heard Douglas Hofstadter call the "abstraction limit". Every human can think thoughts of some "size" where, by "size", we mean its hardness or complexity or abstract-ness, suitably-defined. Any mathematical subject starts easy and becomes increasingly abstract, and Hofstadter's claim is that, at some point, everyone will eventually reach their "abstraction limit" past which they themselves cannot go. Using a metaphor in terms of complex systems design, an engineer who can oversee the design of a 747 may not be able to oversee the design of a Saturn-V rocket. And an engineer who can oversee the design of a Saturn-V rocket may not be able to oversee the design of the ISS. And an engineer who can oversee the design of the ISS may not be able to oversee the design of a hypothetical Death Star. And so on, and so forth. A very complex design can be thought of like a tree data-structure (or perhaps graph data-structure) and the "depth" of that tree is one rough approximation of the "abstractness" of that design, or idea. Everyone eventually reaches their "abstraction limit" past which they cannot go, the "tree" has simply become too deep.

What makes this limit particularly nettlesome is that the prevailing designs for software systems upon which we depend cannot be built to a specification that is at the maximum abstraction limit that the smartest genius among us can handle because then who would maintain it? Thus, we're collectively stuck with tools and systems that can be "grokked" within the average person's abstraction limit or, at least, the average software-developer's abstraction limit.

There are other important limits but these would cause the comment to become very long. In passing, the theory of program-size complexity (Kolmogorov complexity) is an incredibly important limit because it is connected to our abstraction limit. We can only build systems that are not too complicated for us to build and maintain. But what program-size complexity tells us is that, even if we build machines that improve themselves, they cannot self-improve beyond our abstraction-limit (plus whatever computational "endowment" these machines may receive from physics itself, whose magnitude we do not know).

This is one reason why the transhumanist hopes that AI is just going to become ever-more intelligent once it can rewrite itself are sadly doomed to be dashed. As we are learning in the GPT era, it turns out that AI, once we build it, still bears our fingerprints and, thus, our limitations, especially our limitations of abstraction. Obviously, AI can do integration by parts (and explain it) better than the average person, but it can't do it better than the average calculus professor (it can just meet parity, or maybe slightly better if you throw a lot of GPUs at it). This is surprising to a lot of people but it really shouldn't be, because we actually know this from Kolmogorov complexity theory.
https://www.reddit.com/r/cpp/comments/1b1tcjx/how_often_do_people_use_c_types_across_dllso/
https://www.scs.stanford.edu/~dm/blog/param-pack.html
https://www.reddit.com/r/cpp_questions/comments/1b15njz/how_would_you_write_out_c20_templates_to_enable/
level 2
ArtisticPollution448
·
10 hr. ago
The best advice I've heard (and I share) about TZs is this:

Do all your business logic in UTC timestamps only, using your language's best library for time logic.

Under no circumstances do you *ever* try to do time-based math/logic yourself. No, not even if it's "simple".

In Java 8+ that's "java.time", not "Dates" and "Calendars".

Whenever possible, store all your timestamps in the datastore in ISO-8601 formatted strings, in UTC. They're still sortable, searchable, but also human readable.

Transmit your timestamps across wires as ISO-8601 formatted strings, in UTC.

The only place that may know anything about time zones is the front-end, who convert it for the current user in the appropriate way for them, using a library that does it correctly.

There are edge cases, of course ("I need this to run at midnight local time in New York every Sunday"), but for 95% of cases the above system handles most bugs pretty nicely.
![[Pasted image 20250111173043.png]]
![[Pasted image 20250111173541.png]]
https://github.com/emilk/egui/issues/2091
https://github.com/emilk/egui/issues/1042
https://www.reddit.com/r/workingsolution/comments/xrvppd/rust_egui_how_to_upload_an_image_in_egui_and/
https://www.reddit.com/r/cpp_questions/comments/153yg1y/want_to_learn_c_performance_optimization_which/?utm_source=share&utm_medium=ios_app&utm_name=ioscss&utm_term=1
https://raytracing.github.io/books/RayTracingInOneWeekend.html
https://github.com/GlimmerLabs/gigls
https://stackoverflow.com/questions/13442574/how-do-i-determine-if-sys-stdin-is-redirected-from-a-file-vs-piped-from-another