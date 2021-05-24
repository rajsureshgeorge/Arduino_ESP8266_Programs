#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "1e69e8f1dec5400aaed61b9be0455ff0";

char ssid[] = "rpi";
char pass[] = "12345678";


void setup()
{

  Blynk.begin(auth, ssid, pass);
  
}

void loop()
{
  Blynk.run();

}
