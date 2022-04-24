// deklarasi kaki pin digital
#define trigPin 8
#define echoPin 9
#define led 4

void setup() {
  // serial monitor baud rate setting
  Serial.begin(9600);
  // setting output input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  // deklarasi variabel
  long duration, distance;

  // logika bolak balik
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // perhitungan matematika ultrasonik
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  // menampilkan ke serial monitor
    Serial.print("Distance = ");  // output jarak
    Serial.print(distance); // output variabel jarak
    Serial.print("\n");
    delay(500);

  // logika LED on
  if (distance <= 10)
  {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
}
