// deklarasi output LED di pin 2
int led = 2;
// deklarasi input button di pin 4
int button = 4;
// deklarasi nilai button
int buttonVal = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  // deklarasi button nilai button
  buttonVal = digitalRead(button);
  
  // button nilainya high
  if (buttonVal == HIGH) {
    digitalWrite(led, HIGH);
    // holding 2 detik
    delay(2000);
  }
  else {
    digitalWrite(led, LOW);
  }
}
