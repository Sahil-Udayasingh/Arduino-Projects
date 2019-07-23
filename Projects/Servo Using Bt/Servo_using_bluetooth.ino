#include<SoftwareSerial.h>
#include<Servo.h>
Servo x;
int bttx=10;    
int btrx=11;    
SoftwareSerial bluetooth(bttx,btrx);
void setup()
{
  x.attach(2);        
  Serial.begin(9600);
  bluetooth.begin(9600);
}
void loop()
{
  if(bluetooth.available()>0)    
  {
    int pos=bluetooth.read(); 
    Serial.println(pos);
    
     if(pos=='0'){
    x.write(90);
    }

  if(pos=='R')
  {
    x.write(1);
    }
      if(pos=='I')
  {
    x.write(1);
    }

      if(pos=='J')
  {
    x.write(1);
    }

    if(pos=='L')
   {
    x.write(179);
    } 

        if(pos=='G')
  {
    x.write(179);
    }

  if(pos=='H')
  {
    x.write(179);
    }
     if(pos=='B')
    {
      x.write(90);
      }
    
  }
 
}
