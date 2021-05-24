#include "dht.h"
#include "UbidotsMicroESP8266.h"
#define DEVICE  "esp"  // Put here your Ubidots device label
#define VARIABLE  "sensor"
#define DEVICE  "temperature"  // Put here your Ubidots device label
#define VARIABLE  "sensor"
#define TOKEN  "Your Token Here"  // Put here your Ubidots TOKEN
#define ID_1 "Your Variable Here" // Put your variable ID here
#define ID_2 "Your Variable Here" 
#define ID_3 "Your Variable Here" // Put your variable ID here
#define ID_4 "Your Variable Here"
#define WIFISSID "Wifi SSID here" // Put here your Wi-Fi SSID
#define PASSWORD "Wifi Password Here" // Put here your Wi-Fi password

#define LAMP  13  // choose the pin for the RELAY
#define PIR 14   // choose the input pin (for PIR sensor)     

Ubidots client(TOKEN);            
int pir;
int value2;
int value3;
int value4;
dht DHT;

void setup()
{    
    Serial.begin(115200);
    client.wifiConnection(WIFISSID, PASSWORD);
     pinMode(2,OUTPUT);
    pinMode(14,INPUT);
      pinMode(4, OUTPUT);
    pinMode (16,INPUT);
    pinMode (13,OUTPUT);
    client.wifiConnection(WIFISSID, PASSWORD);
Serial.begin(115200);
  pinMode(LAMP, OUTPUT); // declare lamp as output
  pinMode(PIR,INPUT); // declare sensor as input      
}                                                                                                                      
void loop() 
{
  
  
 int value_ldr = analogRead(A0); // read LDR value
  int value_pir = digitalRead(PIR); // read input value
  Serial.println(value_pir);
  Serial.print(value_ldr);
  float detect= (value_ldr*3.3)/1024;
  Serial.println(detect);


if ((detect <= 2.20)&& ( value_pir==1))
 {
       digitalWrite(LAMP,HIGH);  // Turn ON the light
       //delay(6000); 
   pir = 1;
    client.add(ID_1,pir);
    client.sendAll(false);
    delay(1000); 
}
else {
     digitalWrite(LAMP,LOW); // Turn OFF the ligh
  pir = 0;
    client.add(ID_1, pir);
    client.sendAll(false);
    delay(1000);
}  
// HUMIDITY AND TEMPERATURE

DHT.read11(12);
float tempC = DHT.temperature;

float humidity = DHT.humidity;

 value3 = tempC;
    client.add(ID_3, value3);
    client.sendAll(false);
    delay(1000);
    
 value4 = humidity;
    client.add(ID_4, value4);
    client.sendAll(false);
    delay(1000);
   
Serial.print("Temperature (C) = ");
Serial.println(tempC);

Serial.print("Humidity = ");
Serial.println(humidity);
delay(500);

//IFTTT AND UBIDOTS

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
    delay(500);

   // GAS sensing
   
 a= digitalRead(16);
  Serial.println(a);
  if(a==0)
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
        digitalWrite(4, HIGH);
      }
      else
      {
        digitalWrite(4, LOW);
      }
      
    }
    else{
      Serial.println(F("Error getting value"));
    }
    delay(1000);
  
 }
