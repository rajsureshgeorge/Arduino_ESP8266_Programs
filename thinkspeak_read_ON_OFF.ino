//This program is for Thinkspeak Read
#include<ESP8266WiFi.h>
//header file for wifi
#include<ThingSpeak.h>                              //header file for thingspeak

WiFiClient client;                                     //creating clint object
int a;

void setup() 
{
 
    // put your setup code here, to run once:

    Serial.begin(115200);                           //seting band width
    
    WiFi.mode(WIFI_STA);                            //seting esp as station
    WiFi.begin("OnePlus","qwertyuiop");              //seting assespoints name and password

    Serial.println("connecting");
    while(WiFi.status()!=WL_CONNECTED)              //cheacking wifi connected or not
    {
       Serial.println(".....");
       delay(100);
    }
    Serial.println("connected");  
    
    Serial.println(WiFi.localIP());                  //printing esp ip address
    pinMode (16,OUTPUT); 
    ThingSpeak.begin(client);                           //begining and giving clint to thinkspeak

}

void loop() 
{
   // put your main code here, to run repeatedly:
    a=digitalRead (12);
    int x = ThingSpeak.writeField(814449, 1, a, "P7QNHESL6RCSDZJ6"); 
    
        if(x == 200)
    {
        Serial.println("Channel update successful.");
    }
    else
    {
        Serial.println("Problem updating channel. HTTP error code " + String(x));
    }

   float val=0; 
   val = ThingSpeak.readFloatField(814449,1,"W5JIRPWB9TQTMSVP");       //giving chanel_ID and field num for reading thingspeak
   Serial.println(val);  //reading status code if value is read then it will return 200

   if(val == 1)                              
   {
    digitalWrite(16,HIGH);
     Serial.println(val);
   }
   else
   {
    digitalWrite (16,LOW);
   }
  
   delay(2000);


}
