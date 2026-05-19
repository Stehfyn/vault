<!-- generated-from-dump2 -->
# draw-a-ui — Sketch-to-HTML via GPT-4V

Demo from Sawyer Hood: draw a wireframe on a tldraw canvas, pass the rasterized image to GPT-4V, and have it generate the matching HTML/Tailwind. The whole thing is ~200 lines of Next.js - interesting not as a product but as a minimal example of vision-LLM-driven UI generation, predating today's polished "screenshot to code" services.

```text
# Sketch of the prompt (paraphrased from the repo)
# system: "You are an expert tailwind developer. The user will provide a
#  drawing. Reply with a single self-contained HTML file using tailwind CDN."
# user (image + text): the rasterized canvas + "Make this a real webpage."
#
# POST /api/generate { image: dataURL } -> openai.chat with image_url part
```

## References
- <https://github.com/SawyerHood/draw-a-ui>
