// library servo
#include <Servo.h>

// deklarasi Servo
Servo myservo;

// deklarasi led
int led = 4;

// deklarasi variabel posisi motor
int pos = 0;

void setup() {
  pinMode(led, OUTPUT);
  // kaki pin servo digital
  myservo.attach(7);
  Serial.begin(9600);
}

void loop() {
  // goes from 0 degrees to 180 degrees
  for (pos = 0; pos <= 180; pos += 1) {// in steps of 1 degree
    digitalWrite(led, LOW);

    myservo.write(pos);              // tell servo to go to position in variable 'pos'

    Serial.print(pos);
    Serial.print("\n");

    delay(10);                       // tambah tinggi tambah lama sampek
  }

  // led nyala
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    digitalWrite(led, HIGH);

    myservo.write(pos);              // tell servo to go to position in variable 'pos'

    Serial.print(pos);
    Serial.print("\n");

    delay(10);                       // tambah tinggi tambah lama sampek
  }
}
