#define BLYNK_PRINT Serial                                              

#include <ESP8266WiFi.h>                                             
#include <BlynkSimpleEsp8266.h>                                         
char auth[] = "0d634c5c8e6944bc892d12cc9bfc32f2";                      

char ssid[] ="OnePlus";                                                 
char pass[] = "qwertyuiop";                                           
BLYNK_WRITE(V1)                                                      
{
    int Val = param.asInt();                                       

    Serial.println(Val);

    if(Val)
    {
        digitalWrite(16,HIGH);
    }
    else
    {
        digitalWrite(16,LOW);
    }
    
    
    // process received value
}

void setup() 
{
    // put your setup code here, to run once:
    Serial.begin(9600);                                              

    Blynk.begin(auth, ssid, pass);                                       

    pinMode(16,OUTPUT);

}

void loop() 
{
    // put your main code here, to run repeatedly:

    Blynk.run();                                                       

    
}
