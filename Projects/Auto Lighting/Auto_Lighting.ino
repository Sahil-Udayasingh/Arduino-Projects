#include <dht.h>

#define dataPin 2
dht DHT;

int c=0;

void setup() {
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(3)<500)
  c++;
  if(digitalRead(4)<500)
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
  digitalWrite(5,HIGH);
  if(c==0)
  digitalWrite(5,LOW);
  if(c>0)
  digitalWrite(6,HIGH);
   
}
