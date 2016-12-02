#include <Adafruit_NeoPixel.h>

#define OUTPUT_LED_PIN 7
#define LED_PIN_COUNT 11

#define INPUT_GREEN_PIN 2
#define INPUT_RED_PIN 3
#define INPUT_BLUE_PIN 5

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_PIN_COUNT, OUTPUT_LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();

  pinMode(INPUT_GREEN_PIN, INPUT);
  pinMode(INPUT_RED_PIN, INPUT);
  pinMode(INPUT_BLUE_PIN, INPUT);
}

void loop() {
  if (digitalRead(INPUT_GREEN_PIN) == HIGH) {
    colorWipe(strip.Color(0, 255, 0), 0); 
  } else if (digitalRead(INPUT_RED_PIN) == HIGH) {
    colorWipe(strip.Color(255, 0, 0), 0);
  } else if (digitalRead(INPUT_BLUE_PIN) == HIGH) {
    colorWipe(strip.Color(0, 0, 255), 0); 
  } else {
    colorWipe(strip.Color(0, 0, 0), 0); 
  }
}

void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }

  delay(100);
}
