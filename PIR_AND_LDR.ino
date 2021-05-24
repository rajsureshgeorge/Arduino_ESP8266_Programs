//This Program is for Accessing LDR and PIR sensor Data and Uploading it to UBIDOTS
#include "UbidotsMicroESP8266.h"

#define TOKEN  "your Ubidots TOKEN"  // Put here your Ubidots TOKEN
#define ID_1 "your variable ID here" // Put your variable ID here
//#define ID_2 "Your_variable_ID_here" // Put your variable ID here
#define WIFISSID "your Wi-Fi SSID" // Put here your Wi-Fi SSID
#define PASSWORD "your Wi-Fi password" // Put here your Wi-Fi password

#define LAMP  13  // choose the pin for the RELAY
#define PIR 14   // choose the input pin (for PIR sensor)     

Ubidots client(TOKEN);            
int value1;
void setup()
{    
    Serial.begin(115200);
    client.wifiConnection(WIFISSID, PASSWORD);
    
    pinMode(12,OUTPUT);
  
Serial.begin(115200);
  pinMode(LAMP, OUTPUT); // declare lamp as output
  pinMode(PIR,INPUT); // declare sensor as input      
}                                                                                                                      
void loop() 
{
  
  
  int value_ldr = analogRead(A0); // read LDR value
  int value_pir = digitalRead(PIR); // read input value
  Serial.println(value_pir);
  //Serial.print(value_pir);
  float detect= (value_ldr*3.3)/1024;
  Serial.println(detect);


if ((detect <= 2.20)&& ( value_pir==1))
 {
       digitalWrite(LAMP,HIGH);  // Turn ON the light
       //delay(6000); 
    value1 = 1;
    client.add(ID_1, value1);
    client.sendAll(false);
    delay(1000); 
}
else {
     digitalWrite(LAMP,LOW); // Turn OFF the ligh
  value1 = 0;
    client.add(ID_1, value1);
    client.sendAll(false);
    delay(1000);
}       



}
