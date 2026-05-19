<!-- generated-from-dump2 -->
# EDHREC — MTG Commander Recommender (original)

The original Reddit bot behind EDHREC.com — recommends cards for Magic: The Gathering Commander (EDH) decks via item-item collaborative filtering on the corpus of public deck lists. Written in Python; PRAW for Reddit, Redis for the recommendation index, MTGJSON for card metadata. The interesting bit is the recommendation model itself: it's not user-CF (deck builders are mostly anonymous), it's "given a commander + N cards, what other cards co-occur most often in decks of this archetype" — basically `P(card_i | commander, deck-so-far)` from frequency tables, no embeddings. Modern EDHREC is far more elaborate; this repo is the kernel of the idea.

```python
# Conceptual recommendation step:
#   For a deck under construction (commander C, partial set S):
#   score(card x) ~ sum over decks D in corpus where C in D and S ⊂ D:
#                     1 / sqrt(|D|)         # downweight huge decks
#   Recommend the top-K by score, excluding cards already in S.
#
# Implemented in Redis with sorted sets keyed by commander:
#   ZADD  deck:C  count   card_id
#   ZRANGEBYSCORE for top recs after filtering out current deck members.
```

## References
- <https://github.com/donaldpminer/edhrec>
