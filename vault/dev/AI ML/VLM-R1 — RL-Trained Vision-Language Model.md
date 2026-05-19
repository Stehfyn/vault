<!-- generated-from-dump2 -->
# VLM-R1 — RL-Trained Vision-Language Model

Vision-language model trained with reinforcement learning for visual reasoning - applies the DeepSeek-R1 style "chain-of-thought via RL on verifiable answers" recipe to a VLM rather than a pure LLM. Notable because most VLM training in 2024-2025 was SFT-only (instruction tuned); VLM-R1 is one of the early demonstrations that GRPO/PPO-style RL on grounded visual QA actually transfers and yields longer, more correct chains of reasoning over images.

```text
# Conceptual training loop (paraphrased from the repo's scripts):
#   1. Sample a batch of (image, question, ground-truth answer).
#   2. Generate N rollouts from the policy VLM with sampling.
#   3. Reward each rollout: format-correctness reward + answer-correctness reward.
#   4. GRPO update: relative-advantage over the group, no value head.
#   5. Reference KL penalty keeps the model close to the SFT base.
```

## References
- <https://github.com/om-ai-lab/VLM-R1>
