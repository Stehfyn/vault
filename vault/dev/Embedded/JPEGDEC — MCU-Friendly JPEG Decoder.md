<!-- generated-from-dump2 -->
# JPEGDEC — MCU-Friendly JPEG Decoder

Larry Bank's hand-tuned baseline JPEG decoder, deliberately written to fit and run on AVR/ESP32/RP2040-class parts where libjpeg-turbo is laughably too big. Decodes block-by-block with a draw callback so the caller can stream MCUs straight to a TFT framebuffer without ever holding a full-resolution image in RAM. Same author maintains an analogous PNG decoder (PNGdec) and the bb_spi_lcd display library, and the trio is the de-facto stack for "display arbitrary images on a $5 microcontroller."

```cpp
#include <JPEGDEC.h>
JPEGDEC jpeg;

int drawMCU(JPEGDRAW *pDraw) {
    // pDraw->pPixels is an RGB565 tile; blit to display at (pDraw->x, pDraw->y)
    tft.drawBitmap(pDraw->x, pDraw->y, pDraw->iWidth, pDraw->iHeight, pDraw->pPixels);
    return 1; // continue decoding
}

jpeg.openFLASH((uint8_t *)image_data, image_len, drawMCU);
jpeg.setPixelType(RGB565_BIG_ENDIAN);
jpeg.decode(0, 0, 0);
jpeg.close();
```

## References
- <https://github.com/bitbank2/JPEGDEC>
