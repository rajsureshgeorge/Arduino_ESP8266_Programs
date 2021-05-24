//This Arduino Project is Used for Controlling Builtin LED thorugh Network

#include "UbidotsMicroESP8266.h"

#define DEVICE  "temperature"  // Put here your Ubidots device label
#define VARIABLE  "sensor"  // Put here your Ubidots variable label
#define TOKEN  "Your Token Here"  // Put here your Ubidots TOKEN
#define WIFISSID "Put Wifi SSID Here" // Put here your Wi-Fi SSID
#define PASSWORD "Wifi Password Here" // Put here your Wi-Fi password

Ubidots client(TOKEN);

void setup() {
  pinMode (13,INPUT);
  pinMode (16,OUTPUT);
    Serial.begin(115200);
    client.wifiConnection(WIFISSID, PASSWORD);
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, 1);
    //client.setDebug(true); // Uncomment this line to set DEBUG on
}

void loop() {
  digitalRead(13);
    float value = client.getValueWithDevice(DEVICE, VARIABLE);
    if (value != ERROR_VALUE){
      Serial.print(F("value obtained: "));
      Serial.println(value);
      
      if(value == 1)
      {
      digitalWrite (16,HIGH);
      }
      else{
      digitalWrite (16,LOW);}
      } 

    else
    {
       
      Serial.println(F("Error getting value"));
    }
    delay(1000);
}
