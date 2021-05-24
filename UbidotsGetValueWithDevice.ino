//Ubidots Getting Value with Device
#include "UbidotsMicroESP8266.h"

#define DEVICE  "esp"  // Put here your Ubidots device label
#define VARIABLE  "sensor"  // Put here your Ubidots variable label
#define TOKEN  "your Ubidots TOKEN"  // Put here your Ubidots TOKEN
#define WIFISSID "your Wi-Fi SSID" // Put here your Wi-Fi SSID
#define PASSWORD "your Wi-Fi password" // Put here your Wi-Fi password

Ubidots client(TOKEN);

void setup() {

    Serial.begin(115200);
    client.wifiConnection(WIFISSID, PASSWORD);
    pinMode(2,OUTPUT);

    //client.setDebug(true); // Uncomment this line to set DEBUG on
}

void loop() {
    float value = client.getValueWithDevice(DEVICE, VARIABLE);
    if (value != ERROR_VALUE){
      Serial.print(F("value obtained: "));
      Serial.println(value);
      
      if(value == 1)
      {
      digitalWrite (2,HIGH);
      }
      else{
      digitalWrite (2,LOW);}
      } 

    else
    {
       
      Serial.println(F("Error getting value"));
    }
    delay(1000);
}
