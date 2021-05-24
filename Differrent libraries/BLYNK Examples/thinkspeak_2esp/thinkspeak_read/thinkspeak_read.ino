#include<ESP8266WiFi.h>0
#include<ThingSpeak.h>

WiFiClient esp;

void setup() 
{
    // put your setup code here, to run once:

    pinMode(4,OUTPUT);
    
    Serial.begin(115200);
    
    WiFi.mode(WIFI_STA);
    WiFi.begin("No One","nopassword");

    Serial.println("connecting");
    while(WiFi.status()!=WL_CONNECTED)
    {
       Serial.println(".....");
       delay(100);
    }
    Serial.println("connected");  
    
    Serial.println(WiFi.localIP());
    
    ThingSpeak.begin(esp);

}

void loop() 
{
   // put your main code here, to run repeatedly:

 
   int val = ThingSpeak.readIntField(610981,1);  

   int statusCode = ThingSpeak.getLastReadStatus();
   if(statusCode == 200)
   {
     Serial.println(val);
     if(val==1)
     {
        digitalWrite(4,HIGH);
     }
     else
     {
        digitalWrite(4,LOW);
     }
   }
   else
   {
     Serial.println("Problem reading channel. HTTP error code " + String(statusCode)); 
   }
  
   delay(15000);


}
