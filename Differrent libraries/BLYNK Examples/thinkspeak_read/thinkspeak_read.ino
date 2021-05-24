#include<ESP8266WiFi.h>0                            //header file for wifi
#include<ThingSpeak.h>                              //header file for thingspeak

WiFiClient esp;                                     //creating clint object

void setup() 
{
    // put your setup code here, to run once:

    Serial.begin(115200);                           //seting band width
    
    WiFi.mode(WIFI_STA);                            //seting esp as station
    WiFi.begin("No One","nopassword");              //seting assespoints name and password

    Serial.println("connecting");
    while(WiFi.status()!=WL_CONNECTED)              //cheacking wifi connected or not
    {
       Serial.println(".....");
       delay(100);
    }
    Serial.println("connected");  
    
    Serial.println(WiFi.localIP());                  //printing esp ip address
    
    ThingSpeak.begin(esp);                           //begining and giving clint to thinkspeak

}

void loop() 
{
   // put your main code here, to run repeatedly:

   int val = ThingSpeak.readIntField(604389,1);       //giving chanel_ID and field num for reading thingspeak

   int statusCode = ThingSpeak.getLastReadStatus();   //reading status code if value is read then it will return 200
   if(statusCode == 200)                              
   {
     Serial.println(val);
   }
   else
   {
     Serial.println("Problem reading channel. HTTP error code " + String(statusCode)); 
   }
  
   delay(15000);


}
