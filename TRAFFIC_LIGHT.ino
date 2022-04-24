int ledR = 2;
int ledG = 3;
int ledB = 4;

void setup() {
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(ledR, HIGH);
  delay(1000);
  digitalWrite(ledR, LOW);

  digitalWrite(ledG, HIGH);
  delay(1000);
  digitalWrite(ledG, LOW);

  digitalWrite(ledB, HIGH);
  delay(1000);
  digitalWrite(ledB, LOW);
}
