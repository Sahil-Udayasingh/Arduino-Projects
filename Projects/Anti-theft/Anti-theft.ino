 
int buzzer = 13;                
int inputPin = 2;               
int pirState = LOW;             
int val = 0;                    
 
void setup() {
  pinMode(buzzer, OUTPUT);      
  pinMode(inputPin, INPUT);     
 
  Serial.begin(9600);
}
 
void loop(){
  val = digitalRead(inputPin);  
  if (val == HIGH) {            
    digitalWrite(buzzer, HIGH);//Sets the Buzzer HIGH when motion is detected  
    if (pirState == LOW) {
    Serial.print("d");
    pirState = HIGH;
    }
  }
  else {
    digitalWrite(buzzer, LOW); 
    if (pirState == HIGH){
    Serial.print("n");
    pirState = LOW;
    }
  }
}
