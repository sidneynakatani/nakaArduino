int porta_D0 = 2;
int digital_read = 0;

void setup()
{
  pinMode(porta_D0, INPUT);
  Serial.begin(9600);
}
 
void loop(){

  digital_read = digitalRead(porta_D0);
  
  if (digital_read == 1) {
    Serial.println("Vibration detected.");
  }
  delay(100);
}
