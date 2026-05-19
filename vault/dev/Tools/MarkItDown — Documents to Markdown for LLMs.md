<!-- generated-from-dump2 -->
# MarkItDown — Documents to Markdown for LLMs

CLI + Python library that converts almost any document format (`.docx`, `.pptx`, `.xlsx`, `.pdf`, `.html`, `.epub`, audio with Whisper transcription, images with OCR/captions, YouTube transcripts) into clean Markdown. Built primarily to feed LLM context windows: Markdown is the cheapest format the model can losslessly understand (preserves headings, tables, lists) and the conversion strips boilerplate / styling cruft that would otherwise burn tokens. Internally it delegates to format-specific libraries (`mammoth`, `pdfminer.six`, `python-pptx`, `openpyxl`, `azure-ai-document-intelligence` for high-fidelity PDFs) but presents one uniform entry point. Microsoft's own answer to the "RAG ingestion" pipeline problem.

```bash
pip install markitdown

# CLI
markitdown report.docx > report.md
markitdown slides.pptx -o slides.md
markitdown https://en.wikipedia.org/wiki/Markdown > wiki.md
```

```python
from markitdown import MarkItDown

md = MarkItDown()
result = md.convert("paper.pdf")
print(result.text_content)        # markdown string

# With Azure Document Intelligence for high-fidelity PDF tables
md = MarkItDown(docintel_endpoint="https://...azure.com")
print(md.convert("scanned.pdf").text_content)
```

## References
- <https://github.com/microsoft/markitdown>
