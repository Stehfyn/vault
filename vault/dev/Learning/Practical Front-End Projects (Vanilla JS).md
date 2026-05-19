<!-- generated-from-dump2 -->
# Practical Front-End Projects (Vanilla JS)

Curated set of ~20 small browser projects (modal/dialog, drag-and-drop, infinite scroll, lightbox, image cropper, virtual keyboard, draggable list, etc.) implemented in vanilla HTML/CSS/JS with zero dependencies. The pedagogical value is exactly the constraint: each project is the minimum code to do the thing without React/jQuery/lodash, which is roughly how interview-prep questions are evaluated and a good reminder of what the platform actually provides. Each subdirectory is independently openable in a browser.

```html
<!-- Flavour: a vanilla draggable in ~10 lines, no library -->
<div id="box" style="position:absolute;width:80px;height:80px;background:#39f"></div>
<script>
const el = document.getElementById('box');
let dx = 0, dy = 0;
el.onmousedown = (e) => {
  dx = e.clientX - el.offsetLeft;
  dy = e.clientY - el.offsetTop;
  document.onmousemove = (m) => {
    el.style.left = (m.clientX - dx) + 'px';
    el.style.top  = (m.clientY - dy) + 'px';
  };
  document.onmouseup = () => document.onmousemove = null;
};
</script>
```

## References
- <https://github.com/behnamazimi/practical-front-end-projects>
