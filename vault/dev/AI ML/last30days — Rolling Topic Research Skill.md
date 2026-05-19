<!-- generated-from-dump2 -->
# last30days — Rolling Topic Research Skill

Claude Code / Claude Agent "skill" (the `SKILL.md` + supporting scripts format) that researches the recent state of any topic by pulling **rolling-30-day** windows from a fixed set of high-signal sources: Reddit (top + new posts in relevant subs), X/Twitter (kept-up-to-date via Nitter or X API), YouTube (recent uploads via Data API v3), Hacker News (Algolia search), Polymarket (event markets matched by keyword), and a generic web crawl as fallback. The output is a synthesized brief grounded in dated citations — useful as a "did anything important happen this month with X" check that beats a single web search. Architecturally it's a good template for the Claude-skills pattern (a single `SKILL.md` describing trigger conditions + a `tools/` dir of helper scripts the agent invokes).

```text
# SKILL.md activation: when the user asks for recent news / trends / status
# on any topic. The skill enumerates sources and merges results.
#
# Conceptual run shape (the actual scripts in tools/ wrap each source):
#   /last30days "Claude Code SDK"
#       reddit:  searches r/ClaudeAI, r/LocalLLaMA, r/programming for past 30 days
#       x:       searches recent posts (#ClaudeCode, mentions)
#       youtube: data v3 search&type=video&publishedAfter=now-30d
#       hn:      algolia search?query=&numericFilters=created_at_i>now-30d
#       polymarket: matches event names by keyword
#       web:     fallback generic search
#   -> synthesizes a chronological brief with [source, date, link] citations.
```

## References
- <https://github.com/mvanhorn/last30days-skill>
