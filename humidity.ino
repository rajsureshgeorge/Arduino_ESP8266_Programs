//This Project is For sensing Humidity and Temperature using DHT11 and Upload it To Ubidots
#include "dht.h"
#include "UbidotsMicroESP8266.h"

#define TOKEN  "your Ubidots TOKEN"  // Put here your Ubidots TOKEN
#define ID_3 "your variable ID here" // Put your variable ID here
#define ID_4 "your variable ID here"

#define WIFISSID "your Wi-Fi SSID" // Put here your Wi-Fi SSID
#define PASSWORD " your Wi-Fi password" // Put here your Wi-Fi password

Ubidots client(TOKEN);
int value3;
int value4;


dht DHT;

void setup() 
{
  Serial.begin(115200);
    client.wifiConnection(WIFISSID, PASSWORD);


}
void loop() 
{
DHT.read11(12);
float tempC = DHT.temperature;
float humidity = DHT.humidity;

 value3 = tempC;
    client.add(ID_3, value3);
    client.sendAll(false);
    delay(5000);
    
 value4 = humidity;
    client.add(ID_4, value4);
    client.sendAll(false);
    delay(5000);
   
Serial.print("Temperature (C) = ");
Serial.println(tempC);

Serial.print("Humidity = ");
Serial.println(humidity);
delay(3000);
}
