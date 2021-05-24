//ESP8266 act as Wifi Station
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

WiFiClient draogon
int a;
void setup() {
  // pu0t your setup code here, to run once:
Serial.begin(115200);

WiFi.mode (WIFI_STA);
WiFi.begin ("OnePlus","qwertyuiop");

}

void loop() {
  // put your main code here, to run repeatedly:

}
