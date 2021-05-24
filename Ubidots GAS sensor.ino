//Program for Ubidots GAS SENSOR
#include "UbidotsMicroESP8266.h"                         //header file for ubidots

#define TOKEN  "Your Ubidots Token"     // Put here your Ubidots TOKEN
#define ID_1 "your variable ID"                 // Put your variable ID here
#define DEVICE  "gas"  // Put here your Ubidots device label
#define VARIABLE  "sensor"  // Put here your Ubidots variable label

#define WIFISSID "your Wi-Fi SSID"                                // Put here your Wi-Fi SSID
#define PASSWORD "your Wi-Fi password"                            // Put here your Wi-Fi password

int v=0;
int b;

Ubidots client(TOKEN);               
void setup() {
  // put your setup code here, to run once:
  pinMode(16, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(115200);
  client.wifiConnection(WIFISSID, PASSWORD);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  b= digitalRead(16);
  Serial.println(b);
  if(b==0)
 {
    Serial.println("Alert...!!!");
    v=1;
    Serial.println(v);
    client.add(ID_1, v);
    client.sendAll(false); 
    //delay(5000);
 
  }
  else
  {
    Serial.println("Safe");
    v=0;
    client.add(ID_1, v);
    client.sendAll(false);
  }
  float value = client.getValueWithDevice(DEVICE, VARIABLE);
    if (value != ERROR_VALUE){
      Serial.print(F("value obtained: "));
      Serial.println(value);
      if(value==1)
      {
        digitalWrite(13, HIGH);
      }
      else
      {
        digitalWrite(13, LOW);
      }
      
    }
    else{
      Serial.println(F("Error getting value"));
    }
    delay(1000);
  

}
