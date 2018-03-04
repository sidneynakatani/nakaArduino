#include <VirtualWire.h>

const int transmit_pin = 4;


void setup()
{
  Serial.begin(9600); // Velocidade padrão do Uno  
  vw_set_tx_pin(transmit_pin);
  vw_setup(2000);   // Bits per sec
}


void loop()
{

  while(Serial.available()) { 
    String message = Serial.readString();
    int size = message.length() + 1;
    char copy[size];
    message.toCharArray(copy, size);
    vw_send((uint8_t *)copy, size);
    vw_wait_tx(); 
    
  }
  
  delay(1000);
  
}
