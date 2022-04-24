//pin ultrasonik
#define Trigpin 2
#define Echopin 3

#define LEDaman 9
#define LED1 10
#define LED2 11
#define LED3 12

 

void setup() {
  // put your setup code here, to run once:
Serial.begin (9600);
pinMode (Trigpin, OUTPUT);
pinMode (Echopin, INPUT);
pinMode (LEDaman, OUTPUT);
pinMode (LED1, OUTPUT);
pinMode (LED2, OUTPUT);
pinMode (LED3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
long duration, distance;
digitalWrite (Trigpin, LOW);
delayMicroseconds (2);
digitalWrite (Trigpin, HIGH);
delayMicroseconds (10);
digitalWrite (Trigpin, LOW);
duration = pulseIn (Echopin, HIGH);
distance = (duration/2)/ 29.1;

if (distance >= 16)
 { 
  digitalWrite (LEDaman, HIGH);
  digitalWrite (LED1, LOW);
  digitalWrite (LED2, LOW);
  digitalWrite (LED3, LOW);
 }
else
 {
  digitalWrite (LEDaman, LOW); 
 }

if (distance <= 15)
 { 
  digitalWrite (LEDaman, LOW);
  digitalWrite (LED1, HIGH);
  digitalWrite (LED2, LOW);
  digitalWrite (LED3, LOW);
 }
else
 {
  digitalWrite (LED1, LOW); 
 }

if (distance <= 10)
 { 
  digitalWrite (LEDaman, LOW);
  digitalWrite (LED1, LOW);
  digitalWrite (LED2, HIGH);
  digitalWrite (LED3, LOW);
 }
else
 {
  digitalWrite (LED2, LOW); 
 }

if (distance <= 5)
 { 
  digitalWrite (LEDaman, LOW);
  digitalWrite (LED1, LOW);
  digitalWrite (LED2, LOW);
  digitalWrite (LED3, HIGH);
 }
else
 {
  digitalWrite (LED3, LOW); 
 }
 
delay(500);
}
