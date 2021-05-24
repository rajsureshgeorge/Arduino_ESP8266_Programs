#include "UbidotsMicroESP8266.h"                         //header file for ubidots

#define TOKEN  "BBFF-gy8Mi9E7EKZxjBF8KdPfQPbM2M31Xp"     // Put here your Ubidots TOKEN
#define ID_1 "5d0dfde71d84720b3e647354"                  // Put your variable ID here

#define WIFISSID "No One"                                // Put here your Wi-Fi SSID
#define PASSWORD "nopassword"                            // Put here your Wi-Fi password

int value=0;

Ubidots client(TOKEN);                                   //inizilising client

void setup()
{
  // put your setup code here, to run once:

    pinMode(13,INPUT);
    
    Serial.begin(115200);                                 //setting bandwidth
    
    client.wifiConnection(WIFISSID, PASSWORD);            //connecting wifi
}

void loop() 
{
  // put your main code here, to run repeatedly:

    value = digitalRead(13);                              
    
    client.add(ID_1, value);                              //writing value  
    client.sendAll(false);
    delay(5000);
}
