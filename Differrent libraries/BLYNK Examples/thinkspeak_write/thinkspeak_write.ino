#include<ESP8266WiFi.h>                                  //header file for wifi
#include<ThingSpeak.h>                                   //header file for thingspeak

WiFiClient esp;                                          //creating client object59

void setup() 
{
    // put your setup code here, to run once:
    
    Serial.begin(115200);                                 //setting bandwidth
    
    WiFi.mode(WIFI_STA);                                  //setting as station
    WiFi.begin("No One","nopassword");                    //seting asess points name and password

    Serial.println("connecting");                         
    while(WiFi.status()!=WL_CONNECTED)                    //cheaking wifi connected or not
    {
       Serial.println(".....");
       delay(100);
    }
    Serial.println("connected");  
    
    Serial.println(WiFi.localIP());                        //printing esp ip address
    
    ThingSpeak.begin(esp);                                 // begining thingspeak and giving client to it

}

void loop() 
{
    // put your main code here, to run repeatedly:

    float number=analogRead(A0);                            //reading analog value
    delay(50);
    
    int x = ThingSpeak.writeField(604389, 1, number, "3Z0USTF48I46N0KT");         //need to change  //giving channel_ID, Field_no, Analog_value, API_Key. it will return a value. If it is updated then it will return 200.
    
    if(x == 200)
    {
        Serial.println("Channel update successful.");
    }
    else
    {
        Serial.println("Problem updating channel. HTTP error code " + String(x));
    }

}
