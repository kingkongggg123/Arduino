// versi 1

#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

Adafruit_SSD1306 lcd(128, 64, &Wire, 4);

#define btnUp   7
#define btnOk   6
#define btnDown 5
#define btnBack 4

boolean statusBtnUp   = false;
boolean statusBtnOk   = false;
boolean statusBtnDown = false;
boolean statusBtnBack = false;

boolean statusAkhirBtnUp   = false;
boolean statusAkhirBtnOk   = false;
boolean statusAkhirBtnDown = false;
boolean statusAkhirBtnBack = false;

boolean UP   = false;
boolean OK   = false;
boolean DOWN = false;
boolean BACK = false;

int halaman  = 1;
int menuItem = 1;

void setup() {
  Serial.begin(115200);
  lcd.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  lcd.clearDisplay();

  pinMode(btnUp,   INPUT);
  pinMode(btnOk,   INPUT);
  pinMode(btnDown, INPUT);
  pinMode(btnBack, INPUT);
}

void loop() {
  tampil();

  statusBtnUp   = digitalRead(btnUp);
  statusBtnOk   = digitalRead(btnOk);
  statusBtnDown = digitalRead(btnDown);
  statusBtnBack = digitalRead(btnBack);

  saatUpDitekan();
  saatOkDitekan();
  saatDownDitekan();
  saatBackDitekan();

  //  untuk button up
  if (UP && halaman == 1) {
    UP = false;
    menuItem --;
    if (menuItem < 1)menuItem = 4;
  }
  //untuk button down
  if (DOWN && halaman == 1) {
    DOWN = false;
    menuItem ++;
    if (menuItem > 4)menuItem = 1;
  }

  //  untuk button ok
  if (OK) {
    OK = false;
    if (halaman == 1 && menuItem == 1) {
      halaman = 2;
    } else if (halaman == 1 && menuItem == 2) {
      halaman = 3;
    } else if (halaman == 1 && menuItem == 3) {
      halaman = 4;
    } else if (halaman == 1 && menuItem == 4) {
      halaman = 5;
    }
  }

  //  untuk button back
  if (BACK) {
    BACK = false;
    if (halaman == 2 || halaman == 3 || halaman == 4 || halaman == 5) {
      halaman = 1;
    }
  }

  Serial.println(menuItem);
  delay(100);
}

//--------------------------------------------------------------------------------
void saatUpDitekan() {
  if (statusBtnUp != statusAkhirBtnUp) {
    if (statusBtnUp == 0) {
      UP = true;
    }
    delay(50);
  }
  statusAkhirBtnUp = statusBtnUp;
}

void saatOkDitekan() {
  if (statusBtnOk != statusAkhirBtnOk) {
    if (statusBtnOk == 0) {
      OK = true;
    }
    delay(50);
  }
  statusAkhirBtnOk = statusBtnOk;
}

void saatDownDitekan() {
  if (statusBtnDown != statusAkhirBtnDown) {
    if (statusBtnDown == 0) {
      DOWN = true;
    }
    delay(50);
  }
  statusAkhirBtnDown = statusBtnDown;
}

void saatBackDitekan() {
  if (statusBtnBack != statusAkhirBtnBack) {
    if (statusBtnBack == 0) {
      BACK = true;
    }
    delay(50);
  }
  statusAkhirBtnBack = statusBtnBack;
}
//----------------------------------------------------------------------------

//semua yang tampil di lcd ada di fungsi ini
void tampil() {
  if (halaman == 1) {
    lcd.clearDisplay();
    lcd.setTextSize(1);
    lcd.setTextColor(WHITE);
    lcd.setCursor(30, 0);
    lcd.print("DAFTAR MENU");

    if (menuItem == 1) {
      lcd.setCursor(5, 17);
      lcd.setTextColor(WHITE);
      lcd.print("> menuItem 1");
    } else {
      lcd.setCursor(5, 17);
      lcd.setTextColor(WHITE);
      lcd.print("  menuItem 1");
    }

    if (menuItem == 2) {
      lcd.setCursor(5, 27);
      lcd.setTextColor(WHITE);
      lcd.print("> menuItem 2");
    } else {
      lcd.setCursor(5, 27);
      lcd.setTextColor(WHITE);
      lcd.print("  menuItem 2");
    }

    if (menuItem == 3) {
      lcd.setCursor(5, 37);
      lcd.setTextColor(WHITE);
      lcd.print("> menuItem 3");
    } else {
      lcd.setCursor(5, 37);
      lcd.setTextColor(WHITE);
      lcd.print("  menuItem 3");
    }

    if (menuItem == 4) {
      lcd.setCursor(5, 47);
      lcd.setTextColor(WHITE);
      lcd.print("> menuItem 4");
    } else {
      lcd.setCursor(5, 47);
      lcd.setTextColor(WHITE);
      lcd.print("  menuItem 4");
    }

  } else if (halaman == 2) {
    lcd.clearDisplay();
    lcd.setTextSize(2);
    lcd.setTextColor(WHITE);
    lcd.setCursor(25, 25);
    lcd.print("ImamID");
  } else if (halaman == 3) {
    lcd.clearDisplay();
    lcd.setTextSize(2);
    lcd.setTextColor(WHITE);
    lcd.setCursor(10, 15);
    lcd.print("SUBSCRIBE");
    lcd.setCursor(30, 35);
    lcd.print("ImamID");
  } else if (halaman == 4) {
    lcd.clearDisplay();
    lcd.setTextSize(2);
    lcd.setTextColor(WHITE);
    lcd.setCursor(25, 25);
    lcd.print("ini hal 4");
  } else if (halaman == 5) {
    lcd.clearDisplay();
    lcd.setTextSize(2);
    lcd.setTextColor(WHITE);
    lcd.setCursor(25, 25);
    lcd.print("ini hal 5");
  }

  lcd.display();
}

// versi 2
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library.
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET 4         // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3D  ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES 10  // Number of snowflakes in the animation example

#define LOGO_HEIGHT 16
#define LOGO_WIDTH 16

void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 28);
  display.println("Hello world!");
  display.display();
  delay(20000);
  display.clearDisplay();
}

void loop() {
}
