int LED = 13; // Use the onboard Uno LED
int isObstaclePin = 7;  
int isObstacle = HIGH;  

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(isObstaclePin, INPUT);
  Serial.begin(9600);
  
}

void loop() {
  isObstacle = digitalRead(isObstaclePin);
  if (isObstacle == LOW)
  {
    Serial.println("OBSTACLE!!");
    digitalWrite(LED, HIGH);
  }
  else
  {
    Serial.println("Clear");
    digitalWrite(LED, LOW);
  }
  delay(200);
}
