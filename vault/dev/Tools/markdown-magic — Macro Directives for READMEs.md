<!-- generated-from-dump2 -->
# markdown-magic — Macro Directives for READMEs

CLI/Node library that treats markdown comments as macro directives, so READMEs can be regenerated from source-of-truth (TOC, code samples imported from real files, GitHub contributors, package.json version, etc.) without committing drift. The pattern is `<!-- AUTO-GENERATED-CONTENT:START (transform:opts) -->` ... `<!-- AUTO-GENERATED-CONTENT:END -->`; a build step (often in pre-commit or CI) re-runs the transforms and rewrites the block in place. Ships transforms for TOC, code import, file content, and remote URL fetch, plus a plugin API for custom ones. Used heavily by Serverless Framework docs.

```markdown
<!-- AUTO-GENERATED-CONTENT:START (CODE:src=./src/example.js) -->
<!-- The block in between is replaced on each build with the file contents -->
<!-- AUTO-GENERATED-CONTENT:END -->

<!-- AUTO-GENERATED-CONTENT:START (TOC) -->
<!-- Replaced with a table of contents derived from ## headings -->
<!-- AUTO-GENERATED-CONTENT:END -->
```

```bash
# Run from a hook or script
npx markdown-magic README.md
```

## References
- <https://github.com/DavidWells/markdown-magic>
