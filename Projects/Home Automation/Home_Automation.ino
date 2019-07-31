#include <dht.h>
#include<Servo.h>

#define dataPin A3
dht DHT;

int c=0,t;
int pump1=10;
int pump2=12;
int ledPin = 8;                
int inputPin = 2;               
int pirState = LOW;             
int val = 0;
long time1;
float hr,y,z,total,Monthly;
int power=1500;
Servo servo1;             

void setup() {
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);  
  pinMode(ledPin, OUTPUT);      
  pinMode(inputPin, INPUT);
  servo1.attach(7);     
  Serial.begin(9600);
}

void loop() {
  //Auto Lighting
  if(analogRead(A0)<500)                   //Counts Person entering the room
  c++;
  if(analogRead(A1)<500)                   //Counts person exiting the room
  c--;
  //Serial.println(c);
  //delay(500);
  
   int readData = DHT.read11(dataPin);     //Reads the temperature data
   float t = DHT.temperature;
   float h = DHT.humidity;
/*  
  Serial.print("  Temperature = ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print("    Humidity = ");
  Serial.print(h);
  Serial.println(" % ");
  delay(1000);
*/  

  if(c>0&&t>27)                           //Check if there is someone in the room and the temperature is appropirate or not
  {
    digitalWrite(13,HIGH);
    time1=time1+1;
  }
  if(c==0){                                //If no-one is inside switch off the A.C
  digitalWrite(13,LOW);
  digitalWrite(9,LOW);
  }
  if(c>0)
  digitalWrite(9,HIGH);
  if(t<27)
  digitalWrite(13,LOW);
  
  //Electric Bill
  hr=(time1);
  y=(power*hr*(0.00286));
  z=(80*hr*(0.00714));

  total = ((y+z)*6);
  Monthly = (total*30);
  Serial.println(Monthly);
  
  //Anti-theft
   val = digitalRead(inputPin);           
  if (val == HIGH) {            
    digitalWrite(ledPin, HIGH);  
    if (pirState == LOW) {              //Checks if something is detected or not 
    Serial.print("d");                  //Sends bluetooth signal to the anti-theft app
    pirState = HIGH;
    }
  }
  else {
    digitalWrite(ledPin, LOW); 
    if (pirState == HIGH){
    Serial.print("n");
    pirState = LOW;
    }
  }
  //Lock Door Code
  if(Serial.available())
  t=Serial.read();    
  if(t=99)
  servo1.write(90);
  else
  servo1.write(1);

  //Auto-Irrigation Code
  int moisture = analogRead(A2);
  //Serial.println(moisture);
  //delay(100);
  if(moisture>700)                         //Checks the moisture of the soil
  digitalWrite(pump1,LOW);                 //Low because the input is given in relay
  else
  digitalWrite(pump1,HIGH);

  //Auto Water Tank
  int value1 = analogRead(A4);
  int value2 = analogRead(A5);
/*  Serial.println(value1);
    delay(1000);
    Serial.println(value2);
    delay(1000);
*/    
  
  if(value2>700)
  digitalWrite(pump2,HIGH);
  if(value1<650)
  digitalWrite(pump2,LOW);
}
