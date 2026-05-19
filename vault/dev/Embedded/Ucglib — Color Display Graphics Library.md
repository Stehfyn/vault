<!-- generated-from-dump2 -->
# Ucglib — Color Display Graphics Library

Oliver Kraus' color graphics companion to U8g2 — same author, same philosophy of supporting an enormous matrix of display controllers (ILI9325, ST7735, SSD1351, PCF8833, HX8352, etc.) through a uniform abstraction with hand-written assembly hot paths for AVR. Maintenance has largely shifted to U8g2 for monochrome and to controller-specific libs (TFT_eSPI, Adafruit_GFX-derived) for color, so ucglib is mostly relevant as historical/legacy code or for niche controllers nothing else supports.

```cpp
#include <SPI.h>
#include <Ucglib.h>

Ucglib_ILI9341_18x240x320_HWSPI ucg(/*cd=*/9, /*cs=*/10, /*reset=*/8);

void setup() {
    ucg.begin(UCG_FONT_MODE_TRANSPARENT);
    ucg.clearScreen();
    ucg.setFont(ucg_font_ncenR14_tr);
    ucg.setColor(255, 255, 255);
    ucg.setPrintPos(10, 30);
    ucg.print("Hello");
}
```

## References
- <https://github.com/olikraus/ucglib>
