int smokeA0 = A5;
int sensorThreshold = 400;

void setup() {
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0); //input sensor value

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  delay(100);
}
