int led=5;

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop() {
  int moisture = analogRead(A3);
  Serial.println(moisture);
  delay(100);
  if(moisture>700)
  digitalWrite(pump1,HIGH);
  else
  digitalWrite(pump1,LOW);
}
