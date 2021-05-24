#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "0d634c5c8e6944bc892d12cc9bfc32f2";

char ssid[] = "OnePlus";
char pass[] = "qwertyuiop";

int a;

void myTimerEvent()
{
    a=digitalRead(14);
    
    Blynk.virtualWrite(V5,a);
}

void setup() 
{
    // put your setup code here, to run once:
    Serial.begin(9600);

    Blynk.begin(auth, ssid, pass);

    pinMode(14,INPUT);

    // Setup a function to be called every second
    timer setInterval(1000L, myTimerEvent);

} 

void loop() 
{
    // put your main code here, to run repeatedly:
    Blynk.run();
    
}
