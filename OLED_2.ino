#include<Wire.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>

const int lebar=128;
const int tinggi=64;
const int reset=4;

Adafruit_SSD1306 oled(lebar,tinggi,&Wire,reset);

void setup() {
  oled.begin(SSD1306_SWITCHCAPVCC,0x3C);
  oled.clearDisplay();
}

void loop() {
  oled.setTextSize(2);
  oled.setTextColor(WHITE);
  oled.setCursor(12,15);
  oled.println("Life Tech");
  oled.setCursor(25,33);
  oled.println("Youtube");
  oled.display();
}
