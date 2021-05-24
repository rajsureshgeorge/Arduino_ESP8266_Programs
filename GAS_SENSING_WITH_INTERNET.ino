//This Program is For Sensing any Gas using the GAS sensor and uploading it to UBIDOTS

#include "UbidotsMicroESP8266.h"

#define TOKEN  "Your Ubidots Token here"  // Put here your Ubidots TOKEN
#define ID_2 "Your Variable ID here" // Put your variable ID here

#define WIFISSID "Wifi SSID here" // Put here your Wi-Fi SSID
#define PASSWORD "Wifi Passsword" // Put here your Wi-Fi password

Ubidots client(TOKEN);
int value2;

void setup(){
    Serial.begin(115200);
    client.wifiConnection(WIFISSID, PASSWORD);
pinMode (16,INPUT);
    pinMode (13,OUTPUT);
}

void loop(){
      
  int sensorValue = digitalRead(16);

  Serial.println(sensorValue);
  delay (200);
   delay (2000);
  if (sensorValue==1)
  {
    digitalWrite (13,HIGH);
     value2 = 1;
    client.add(ID_2, value2);
    client.sendAll(false);
    delay(5000);
    }
    else {
      
    digitalWrite(13,LOW);
   value = 0;
    client.add(ID_2, value2);
    client.sendAll(false);
    delay(5000);
    }
    

    
}
