#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "c36c395e369b4f0e8eeaee6fb5018408";

char ssid[] = "No One";
char pass[] = "nopassword";

void setup() 
{
    // put your setup code here, to run once:

     Serial.begin(9600);

     Blynk.begin(auth, ssid, pass);

}

void loop() 
{
    // put your main code here, to run repeatedly:

    Blynk.run();

}
