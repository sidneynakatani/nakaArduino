int pin_d = 2;  //Arduino Pin D2 to Sensor Pin D0 
int pin_a = A5; //Arduino Pin A5 to Sensor Pin A0 


int val_d = 0; //Buffer Digital Value
int val_a = 0; //Buffer Analogic Value

int pin_5 = 5; //Pin D5 to connect Led


void setup() {

  //Setup Pins
  pinMode(pin_d, INPUT);
  pinMode(pin_a, INPUT);
  pinMode(pin_5, OUTPUT);

  //Setup Serial
  Serial.begin(9600);
}

void loop() {

  val_d = digitalRead(pin_d); //Read Digital Pin and buffer
  val_a = analogRead(pin_a);  //Read Analogic Pin and buffer

  Serial.print("Digital : ");
  Serial.print(val_d);
  Serial.print(" - Analogic : ");
  Serial.println(val_a);

  digitalWrite(pin_5, LOW);
 
  // Low water quantity in sensor surface 
  if (val_a >900 && val_a <1024){

    delay(1000);
    digitalWrite(pin_5, HIGH);
   
  }

  // Medium water quantity in sensor surface 
  if (val_a >400 && val_a <900) {

    delay(500);
    digitalWrite(pin_5, HIGH);
 
  }

  // High water quantity in sensor surface 
  if (val_a > 0 && val_a <400){

    delay(100);
    digitalWrite(pin_5, HIGH);
   
  }

 
}
