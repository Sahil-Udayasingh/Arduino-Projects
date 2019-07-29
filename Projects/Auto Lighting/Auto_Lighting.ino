#include <dht.h>

#define dataPin 2
dht DHT;

int c=0;

void setup() {
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(11,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(analogRead(3)<500)
  c++;
  if(analogRead(4)<500)
  c--;
  Serial.println(c);
  delay(500);

  int readData = DHT.read11(dataPin);
  float t = DHT.temperature;
  float h = DHT.humidity;
  
  Serial.print("  Temperature = ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print("    Humidity = ");
  Serial.print(h);
  Serial.println(" % ");
  
  delay(1000);

  if(c>0&&t>27)
  digitalWrite(11,HIGH);
  if(c==0)
  digitalWrite(11,LOW);
  if(c>0)
  digitalWrite(13,HIGH);
   
}
