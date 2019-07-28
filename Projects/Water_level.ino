void setup() {
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  pinMode(11,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  int value1=analogRead(A4);
  int value2=analogRead(A5);
  /*
  Serial.println(value1);
  delay(1000);
  Serial.println(value2);
  */

  if(value2>1000)           //max value
  digitalWrite(11,HIGH);
  if(value1<800)            //min value
  digitalWrite(11,LOW);     // pump connected to relay
  
  
}
