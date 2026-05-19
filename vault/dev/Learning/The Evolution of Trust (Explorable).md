<!-- generated-from-dump2 -->
# The Evolution of Trust (Explorable)

Nicky Case's interactive explorer for the Iterated Prisoner's Dilemma. Hosted at ncase.me/trust; the repo is the HTML/JS/CSS source. Walks the reader through Axelrod's tournament strategies (Tit-for-Tat, Grim Trigger, Always-Cheat, Detective, etc.) with playable sliders for noise level and copy-error rate, ending in the empirical conclusion that under low noise Tit-for-Tat dominates and under high noise more forgiving strategies (Generous TFT, Pavlov/Win-Stay-Lose-Shift) win. A canonical example of an "explorable explanation."

```text
# Open ncase.me/trust or run the static site locally:
#   git clone ...; cd trust; python3 -m http.server
# The interesting math is small - payoff matrix per round:
#   both cooperate:  (+2, +2)
#   both cheat:      (-1, -1)
#   I cheat, you C:  (+3, -1)
# Run an N-round tournament with mixed-strategy population and watch
# which strategy proliferates over generations.
```

## References
- <https://github.com/ncase/trust>
