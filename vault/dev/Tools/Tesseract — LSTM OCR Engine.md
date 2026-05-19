<!-- generated-from-dump2 -->
# Tesseract — LSTM OCR Engine

Tesseract - the long-running open-source OCR engine, originally from HP, given to Google, now community-maintained. Since v4 the recognition core is an LSTM (a sequence-to-sequence neural model over text-line images); the v3 codepath (legacy classifier + dictionary lookup) is still in the source for compatibility but discouraged. The standout features for new users are the per-language `.traineddata` packs (over 100 languages, downloadable per locale) and `--psm` page-segmentation modes (which let you trade layout-analysis cost for accuracy depending on whether you're OCRing a book, a receipt, or a single word).

```text
# Command-line:
$ tesseract scan.png out -l eng+deu --psm 6 --oem 1
# psm 6 = "assume a single uniform block of text"
# oem 1 = "neural nets LSTM only" (most accurate post-v4)

# Library (libtesseract C++):
tesseract::TessBaseAPI api;
api.Init(NULL, "eng");
api.SetImage(pixData, w, h, bytesPerPixel, bytesPerLine);
char* text = api.GetUTF8Text();
puts(text);
delete[] text;
```

## References
- <https://github.com/tesseract-ocr/tesseract>
