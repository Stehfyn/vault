<!-- generated-from-dump2 -->
# GitHub spec-kit — Spec-Driven Agent Workflow

GitHub's opinionated workflow + CLI for "spec-driven development" with agentic coding tools (Claude Code, Copilot, etc.) — the pitch is that LLMs build better code when you make them write a **specification** and a **plan** before the implementation, and have them check their work against that spec rather than against the immediate prompt. spec-kit scaffolds a `specify/` directory with template Markdown files (`spec.md`, `plan.md`, `tasks.md`) and slash commands (`/specify`, `/plan`, `/tasks`) that the agent invokes to fill them in iteratively. Worth reading as an early formalization of the agentic-coding workflow pattern: brief in prose, refine into a plan, decompose into ordered tasks, then implement task-by-task with verification gates.

```text
# Typical session shape (in Claude Code / Copilot Chat):
#
#   /specify  "Add a CSV export endpoint to the report API"
#       -> agent writes specify/spec.md with: user story, requirements,
#          non-goals, constraints, open questions.
#
#   /plan
#       -> agent writes specify/plan.md: file-by-file changes, data model
#          edits, test strategy, dependencies.
#
#   /tasks
#       -> agent writes specify/tasks.md: ordered, single-PR-sized tasks.
#
#   /implement   (or just "do task 1")
#       -> agent picks task 1, edits files, re-reads spec to verify.
```

## References
- <https://github.com/github/spec-kit>
