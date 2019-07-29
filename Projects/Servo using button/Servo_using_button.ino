
#include<Servo.h>
Servo x;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  x.attach(9);
  Serial.begin(9600);
}

void loop() {
  
  int value=analogRead(A0);
  Serial.println(value);
  //delay(1000);
  if(value==0)
  x.write(90);
  else
  x.write(1);
}
