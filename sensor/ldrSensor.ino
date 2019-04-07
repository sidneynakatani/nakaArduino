const int pinSensor = 10; 

void setup() {
  
  Serial.begin(9600); 
  pinMode (pinSensor, INPUT); 
}

void loop() {
  if(digitalRead(pinSensor) == HIGH){ 
     Serial.println('Presença de luz.'); 
     delay(500);
  }
}
