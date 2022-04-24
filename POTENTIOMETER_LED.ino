// deklarasi pin output LED || fyi =negasi bisa menghasilkan voltase 0V-5V
int led = 6;
// deklarasi pin input POT
int pinPot =  A0;
// deklarasi nilai potensiometer
int potVal = 0;

void setup() {
  // pin LED 6 sebagai output
  pinMode(led, OUTPUT);
}

void loop() {
  // membaca input pin analog yang masuk
  potVal = analogRead(pinPot);
  // range nilai potensiometer dari analog ke digital
  potVal = map(potVal, 0, 1023, 0, 255);

  // menyalakan LED (pin, nilai atau kondisi) redup terang
  analogWrite(led, potVal);

  // logika menyalakan LED jika menggunakan syarat nilai potensio
  /*
  if (potVal == 255) {
    analogWrite(led, HIGH);
  }
  else
  {
    analogWrite(led, LOW);
  }*/
}
