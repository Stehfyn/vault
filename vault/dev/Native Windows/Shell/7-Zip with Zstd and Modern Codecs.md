# 7-Zip with Zstd and Modern Codecs

Fork of Igor Pavlov's 7-Zip that bolts on Brotli, Fast-LZMA2, Lizard, LZ4/LZ5, and Zstandard codecs via the standard `ICompressCoder2` plug-in interface. Useful when you want zstd-in-.7z interop with tools that already speak the 7z container, or when you need a drop-in replacement for the official 7-Zip shell DLL that recognizes those additional methods. Codec IDs are picked in the vendor-private range so archives created here remain readable by anyone who installs this build.

## References
- <https://github.com/mcmilk/7-Zip-zstd>
