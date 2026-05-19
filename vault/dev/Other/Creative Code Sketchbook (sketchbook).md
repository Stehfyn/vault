<!-- generated-from-dump2 -->
# Creative Code Sketchbook (sketchbook)

Personal sketchbook of generative-art / creative-coding experiments — Processing (~63%), Python with Pillow, vanilla JS/Canvas. Not a library, not a tutorial: a "this is what I tried last weekend" repo. Worth noting only as a reminder that the lowest-friction path into procedural visuals remains Processing / p5.js, and Pillow is enough for static generative imagery without dragging in OpenCV. Use as a browsing artifact, not a dependency.

```processing
// Flavour — a typical Processing sketch this repo would house:
// Lissajous-style curve with mouse-driven phase.
void setup() {
  size(800, 800);
  noFill();
  stroke(255, 30);
  strokeWeight(0.5);
  background(20);
}
void draw() {
  background(20);
  float phase = map(mouseX, 0, width, 0, TWO_PI);
  beginShape();
  for (float t = 0; t < TWO_PI; t += 0.005) {
    float x = width/2  + 300 * sin(3*t + phase);
    float y = height/2 + 300 * sin(5*t);
    vertex(x, y);
  }
  endShape();
}
```

## References
- <https://github.com/grakkee/creative_code>
