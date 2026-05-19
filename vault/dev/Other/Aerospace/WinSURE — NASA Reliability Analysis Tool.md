<!-- generated-from-dump2 -->
# WinSURE — NASA Reliability Analysis Tool

NASA-published Windows port of SURE — the "Semi-Markov Unreliability Range Evaluator," a fault-tolerance analysis tool from NASA Langley used to compute reliability bounds for fault-tolerant computer systems (aircraft flight computers, spacecraft guidance, etc.). Models the system as a continuous-time semi-Markov chain with transitions for fault arrival, fault recovery, and reconfiguration; evaluates upper and lower bounds on the probability of system failure over a mission lifetime. Niche but historically important — referenced in DO-178C / DO-254 safety analyses.

```text
# Conceptual input deck (paraphrased — see NASA TM-87601 for SURE's input syntax)
INITIAL_STATE = 0;
TRANSITION FROM 0 TO 1 = LAMBDA;       LAMBDA = 1e-5;  # fault arrival per hour
TRANSITION FROM 1 TO 2 = RHO;          RHO    = 100;   # recovery rate
TRANSITION FROM 1 TO 99 = (1 - C);     C      = 0.999; # recovery coverage
FAILURE_STATES = { 99 };
MISSION_TIME = 10 hr;
RUN; PRINT bounds_on_failure_probability;
```

## References
- <https://github.com/nasa/WinSURE>
