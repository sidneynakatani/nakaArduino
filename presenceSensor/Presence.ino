int led = 2;
int data = 7;
int sensor;  

void setup() {
  pinMode(led, OUTPUT);   //Led Pin
  pinMode(data, INPUT);   //Data input
  Serial.begin(9600);
}

void loop() {
 sensor = digitalRead(data); //Read sensor data
 if (sensor == LOW) {
    digitalWrite(led, LOW);
    Serial.println("Off.");
 } else {
    digitalWrite(led, HIGH);
    Serial.println("On.");
 }
}
