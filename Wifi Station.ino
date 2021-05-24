//Basic ESP8266 Client Program for connecting to a AP
#include <ESP8266WiFi.h>
void setup() {
Serial.begin(9600);
WiFi.mode (WIFI_STA);
WiFi.begin("Wifi SSID","WIFI PASSWORD");
Serial.println("CONNECTING");
while (WiFi.status()!= WL_CONNECTED)
{
  Serial.println(".........");
delay(10);
}
Serial.println(WiFi.localIP());
}
void loop() {
  
}
