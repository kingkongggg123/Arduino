#include <TM1637Display.h>

#define CLK 3
#define DIO 2

unsigned int angka = 0;
TM1637Display display(CLK, DIO);

void setup()
{
  display.setBrightness(0x0f);  //maximum brightness
}

void loop()
{
  for(angka = 0; angka < 9999; angka++) 
  {
    display.showNumberDec(angka); //tampilkan angka
    delay(100);  
  }
}

Atau

#include <TM1637.h>

int CLK = 2;
int DIO = 3;

TM1637 tm(CLK,DIO);

void setup() {
  // put your setup code here, to run once:
  tm.init();

  //set brightness; 0-7
  tm.set(2);
}

void loop() {
  // put your main code here, to run repeatedly:

  // example: "12:ab"
  // tm.display(position, character);
 

  // example: "1234"
  displayNumber(1234);

  delay(1000);
}

void displayNumber(int num){   
    tm.display(3, num % 10);   
    tm.display(2, num / 10 % 10);   
    tm.display(1, num / 100 % 10);   
    tm.display(0, num / 1000 % 10);
}
