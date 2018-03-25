#include <UIPEthernet.h>
#include "DHT.h"
#define DHTPIN A2     // Analogic A2 pin
#define DHTTYPE DHT11 // DHT 11

DHT dht(DHTPIN, DHTTYPE);
EthernetServer server = EthernetServer(8080);

void setup() {
  
 Serial.begin(9600);

 byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
 byte gateway[] = { 136,155,57,255  };
 byte subnet[] = { 255, 255, 255, 0 };

 IPAddress ip(136,155,57,119);
 Ethernet.begin(mac, ip, gateway, subnet);

 server.begin();
 dht.begin();
 
}

void loop() {

 float h = dht.readHumidity();
 float t = dht.readTemperature();
 
 size_t size;

 if (EthernetClient client = server.available()) {
  
     while((size = client.available()) > 0) {
       uint8_t* msg = (uint8_t*)malloc(size);
       size = client.read(msg,size);
       Serial.write(msg,size);
       free(msg);
     }
   
     client.print("Humidity: ");
     client.print(h);
     client.println(" % ");
    
     client.print("Temperature: ");
     client.print(t);
     client.println(" C ");
     client.stop();
  }
  
}
