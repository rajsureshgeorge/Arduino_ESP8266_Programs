#include<ESP8266WiFi.h>
#include<ThingSpeak.h>

WiFiClient esp;

int num;

void setup() 
{
    // put your setup code here, to run once:

    Serial.begin(115200);
    
    pinMode(12,INPUT);
    
    Serial.println("hi");
    
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

    num=digitalRead(12);
    delay(50);
    
    int x = ThingSpeak.writeField(610981, 1, num, "EHW4OOJ80PZO4YR9");//need to change
    
    Serial.println("num=" + num);
    
    if(x == 200)
    {
        Serial.println("Channel update successful.");
    }
    else
    {
        Serial.println("Problem updating channel. HTTP error code " + String(x));
    }

}
