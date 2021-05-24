#define BLYNK_PRINT Serial                                              //defining serial as BLYNK_PRINT

#include <ESP8266WiFi.h>                                                //header file for wifi
#include <BlynkSimpleEsp8266.h>                                         //blynk app header file

char auth[] = "0d634c5c8e6944bc892d12cc9bfc32f2";                       //Auth Token will be get from blynk

char ssid[] = "OnePlus";                                                 //Assespoint name
char pass[] = "qwertyuiop";                                             //Password

int Val,a;                                                              //declering variables

void setup() 
{
    // put your setup code here, to run once:
    Serial.begin(9600);                                                 //seting serial bantwidth

    Blynk.begin(auth, ssid, pass);                                      //seting blynk and wifi 

    pinMode(14,INPUT);                                                  //setting 12th pin as input

} 

void loop() 
{
    Blynk.run();                                                        //runing Blynk function

  //a=digitalRead(12);
   //Serial.print(a);
    if(digitalRead(14)!=1)                                                //reading and cheacking 12th pin
    {
        Val=1;
        Blynk.virtualWrite(V1,Val);                                     //passing value to vertual 1
        Serial.println("ON");
    }
    else
    {
        Val=0;
        Blynk.virtualWrite(V1,Val); 
        Serial.println("OFF");
    }

}
