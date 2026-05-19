<!-- generated-from-dump2 -->
# GPT-2 Inference in Pure C

GPT-2 inference in pure C; useful to see the raw math of attention and MLP layers.

```c
float scale = 1.0f / sqrtf((float)head_dim);
for (int t = 0; t <= seq_len; t++) {
  float dot = 0.0f;
  for (int d = 0; d < head_dim; d++) dot += qh[d] * kh[t * head_dim + d];
  attn_scores[t] = dot * scale;
}
softmax(attn_scores, seq_len + 1);
```

## References
- <https://github.com/carlini/c-chat-gpt-2>
