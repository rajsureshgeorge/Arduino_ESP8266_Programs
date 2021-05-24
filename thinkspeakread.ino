#include <ESP8266WiFi.h>
#include "ThingSpeak.h"

char ssid[] = "No One";   // your network SSID (name) 
char pass[] = "nopassword";   // your network password
int keyIndex = 0;            // your network key Index number (needed only for WEP)
WiFiClient  client;

unsigned long weatherStationChannelNumber = 604389;
unsigned int temperatureFieldNumber = 4;

void setup() 
{
  // put your setup code here, to run once:

  Serial.begin(115200);
  while (!Serial); // wait for serial port to connect. Needed for Leonardo native USB port only

  // check for the presence of the shield:
  while(WiFi.status() != WL_CONNECTED)   
  {
    Serial.println("WiFi not connected");// don't continue:
    while (true);
  }

  ThingSpeak.begin(client);  // Initialize ThingSpeak
  
}

void loop() {
  // put your main code here, to run repeatedly:

  // Connect or reconnect to WiFi
  if(WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println("SECRET_SSID");
    while(WiFi.status() != WL_CONNECTED)
    {
      WiFi.begin(ssid, pass);  // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print(".");
      delay(5000);     
    } 
    Serial.println("\nConnected");
  }

  // Read in field 4 of the public channel recording the temperature
  float temperatureInF = ThingSpeak.readFloatField(weatherStationChannelNumber, temperatureFieldNumber);  

  // Check the status of the read operation to see if it was successful
  statusCode = ThingSpeak.getLastReadStatus();
  if(statusCode == 200)
  {
    Serial.println("Temperature at MathWorks HQ: " + String(temperatureInF) + " deg F");
  }
  else
  {
    Serial.println("Problem reading channel. HTTP error code " + String(statusCode)); 
  }
  delay(15000); // No need to read the temperature too often.

  // Read in field 1 of the private channel which is a counter  
  long count = ThingSpeak.readLongField(counterChannelNumber, counterFieldNumber, myCounterReadAPIKey);  

   // Check the status of the read operation to see if it was successful
  statusCode = ThingSpeak.getLastReadStatus();
  if(statusCode == 200)
  {
    Serial.println("Counter: " + String(count));
  }
  else
  {
    Serial.println("Problem reading channel. HTTP error code " + String(statusCode)); 
  }
  
  
  delay(15000); // No need to read the counter too often.
}
