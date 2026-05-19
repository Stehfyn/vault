<!-- generated-from-dump2 -->
# Erdős Open Problems Database

Community database of Paul Erdos's open problems, maintained alongside Terence Tao's erdosproblems.com. The repo holds the structured data (one Markdown file per problem with a YAML frontmatter capturing status, prize amount, references, related problems). Useful as a curated index of "what's known and unknown" in combinatorics, additive/multiplicative number theory, and Ramsey theory - every entry links to the SOTA paper as of the last update.

```text
# Entry shape (paraphrased):
---
id: 1
title: "On the largest sum-free subset of {1,...,N}"
status: open                # open / solved / partial
prize: $500
solver: ~                   # filled when status: solved
references:
  - "Eberhard, Green, Manners (2014)"
related: [13, 220]
---
Statement of the problem and known partial results...
```

## References
- <https://github.com/teorth/erdosproblems>
