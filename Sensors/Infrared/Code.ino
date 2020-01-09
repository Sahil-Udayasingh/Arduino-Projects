void setup() {
  pinMode(A4,INPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(11,OUTPUT);
  digitalWrite(A2,HIGH);
  digitalWrite(A3,LOW);
  Serial.begin(9600);
}

void loop() {
    
  Serial.println(analogRead(A4));
  if(analogRead(A4)<500)
  digitalWrite(11,HIGH);
  else
  digitalWrite(11,LOW);
}
