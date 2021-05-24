//This Prorgram is For ESP8266 to become a Station
#include <ESP8266WiFi.h>
WiFiServer drogon(80);
void setup() {
Serial.begin(9600);
WiFi.mode (WIFI_AP);
WiFi.softAP("Your Wifi SSID","Your Wifi password");
Serial.println(WiFi.softAPIP());
drogon.begin();
}
void loop() 
{
  WiFiClient A1;
  while((A1=drogon.available())==0);
  Serial.println (A1.remoteIP());
  while((A1.connected()!=0&&A1.available())==0)
  {
    delay(100);
  }        
 String req= A1.readStringUntil('\r');
 Serial.println(req);
}
