#include <Adafruit_NeoPixel.h>

#define PIXEL_PIN 2
#define NUMPIXELS 12
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

uint32_t indicatorColor[2] = {
  pixels.Color(255, 255, 0),
  pixels.Color(255, 0, 0)
};
int indicatorIndex;

void pixelDance() {
  for (int i = 0; i < NUMPIXELS; ++i) {
    pixels.setPixelColor(i, pixels.Color(0, 100, 255));
    pixels.show();
    delay(100);
  }
}

void setupPixels() {
  pixels.begin();
  pixels.setBrightness(200);
  pixelDance();
}

void neoPixelsOff() {
  for (int i = 0; i < 12; ++i) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  }
}
