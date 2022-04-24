// library DHT
#include "DHT.h"

// input pin 2 ke arduino untuk kaki data DHT
#define DHTPIN 2  // definisikan pin yang digunakan utk sensor DHT11

// pin 4  sebagai output
int led = 4;

#define DHTTYPE DHT11
//#define DHTTYPE DHT22 // DHT 22 (AM2302)
//#define DHTTYPE DHT21 // DHT 21 (AM2301)

// wajib
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // input serial monitor baudrate
  Serial.begin(9600);
  // output ke serial monitor
  Serial.println("DHTxx test!");

  // deklarasi pin LED (4) sebagai output
  pinMode(led, OUTPUT);

  // dht running program
  dht.begin();
}

void loop() {
  // Baca humidity dan temperature
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Cek hasil pembacaan, dan tampilkan bila ok
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } else {
    Serial.print("Humidity: ");  //kelembaban
    Serial.print(h);
    Serial.print(" %t");
    Serial.print(" Temperature: ");
    Serial.print(t);
    Serial.println(" *C");
    delay(250);

    // menyalakan lampu jika suhu lebih dari 31
    if (t >= 31) {
      // lampu dari output digital menyala
      digitalWrite(led, HIGH);
    }
  }
}
