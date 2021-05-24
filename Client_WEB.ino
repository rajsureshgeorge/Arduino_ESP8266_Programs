//ESP8266 as AP and Controlling PIN
#include <ESP8266WiFi.h>
WiFiServer drogon(80);
void setup() {
Serial.begin(9600);
pinMode(16,OUTPUT);
WiFi.mode (WIFI_AP);
WiFi.softAP("Wifi SSID here","Wifi Password Here");
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
 if(req.indexOf("ON")!=-1)
 digitalWrite(16,HIGH);
 else 
 digitalWrite(16,LOW);
 
}
