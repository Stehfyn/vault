<!-- generated-from-dump2 -->
# Linus Rants — LKML Sentiment Dataset

Scrape of the Linux Kernel Mailing List (LKML) filtered to messages from Linus Torvalds, run through a sentiment analyzer, and ranked by negativity score. The dataset, not the analyzer, is the artifact: the famous "WHAT THE F*CK IS WRONG WITH YOU PEOPLE?" replies, all in one place with reproducible scoring. Useful (a) as a teaching corpus for fine-grained sentiment classification on technical English (most consumer SA models trained on movie reviews flunk on the kernel-mailing-list register) and (b) as a research artifact for software-collaboration tone studies.

```python
# Conceptual reproduction (the repo has the real scraped data):
# 1. Walk LKML archive (lkml.org/lkml/ or lore.kernel.org), filter author.
# 2. Run sentiment classifier per message body.
# 3. Sort descending by negativity score.

from transformers import pipeline
clf = pipeline("sentiment-analysis", model="distilbert-base-uncased-finetuned-sst-2-english")
score = clf("THIS IS THE STUPIDEST FUCKING THING I HAVE EVER SEEN")
# -> [{'label': 'NEGATIVE', 'score': ~0.999}]
```

## References
- <https://github.com/corollari/linusrants>
