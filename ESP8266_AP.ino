//ESP8266 as a Access Point
#include <ESP8266WiFi.h>
WiFiServer drogon(80);
void setup() {
Serial.begin(9600);
WiFi.mode (WIFI_AP);
WiFi.softAP("Wifi SSID","Wifi Password");
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
