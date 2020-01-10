int pump1=11;

void setup() {
  Serial.begin(9600);
  pinMode(11,OUTPUT);
}

void loop() {
  int moisture = analogRead(A0);
  Serial.println(moisture);
  delay(100);
  if(moisture>700)
  digitalWrite(pump1,LOW); //Relay
  else
  digitalWrite(pump1,HIGH);
}
