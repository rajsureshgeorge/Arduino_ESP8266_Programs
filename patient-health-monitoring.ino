#include "ThingSpeak.h"
    #include <SPI.h>
    #include <Ethernet.h>
    byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
    EthernetClient client;

#define USE_ARDUINO_INTERRUPTS true    
#include <PulseSensorPlayground.h>        


const int PulseWire = 3;       
const int LED13 = 13;          
int Threshold = 550;  
int error =0; 

                               
PulseSensorPlayground pulseSensor;  


unsigned long myChannelNumber = 445231;
const char * myWriteAPIKey = "Your Key here";

int tempc;  

float vout;
int ECG=0;
int myBPM=0;
int emergency=0;

const int drcall=6;



void setup() {

  Serial.begin(9600);
        Ethernet.begin(mac);
          ThingSpeak.begin(client);
  pinMode(2,INPUT);
  pinMode(3,INPUT);

  pinMode(drcall,INPUT);



  pulseSensor.analogInput(PulseWire);   
  pulseSensor.blinkOnPulse(LED13);       
  pulseSensor.setThreshold(Threshold);  

}

void loop() {


    myBPM = pulseSensor.getBeatsPerMinute();  // Calls function on our pulseSensor object that returns BPM as an "int".
                                               // "myBPM" hold this BPM value now. 

if (pulseSensor.sawStartOfBeat()) {            // Constantly test to see if "a beat happened". 
 Serial.println("?  A HeartBeat Happened ! "); // If test is "true", print a message "a heartbeat happened".
 Serial.print("BPM: ");
 
 
 Serial.println(myBPM);                        // Print the value inside of myBPM. 
}

  delay(20); 
  
  if((digitalRead(2)==HIGH)||(digitalRead(2)==HIGH)){
  
   

      Serial.println(analogRead(A2));
}

      if(analogRead(A2)>350)
      {
      ECG=80;
      Serial.println("NORMAL ECG");
      
      }

      else
      {
        ECG=30;
        Serial.println("UBNORMAL ECG");
      }
  
  delay(100);
 

  vout=analogRead(A4);
  delay(100);
vout=(vout*500)/1023;
tempc=vout; // Storing value in Degree Celsius
tempf=(vout*1.8)+32; // Converting to Fahrenheit 

Serial.println(tempc);


  
if(digitalRead(drcall)==HIGH)
{
  emergency=1;
  Serial.println("Emergency alert");
}
else
{
    emergency=0;
  Serial.println("NO Emergency alert");
}
 


ThingSpeak.setField(1,tempc);
  ThingSpeak.setField(2,myBPM);
  ThingSpeak.setField(3,ECG);
  ThingSpeak.setField(4,emergency);
  

  
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);  

  delay(3000); // ThingSpeak will only accept updates every 30 seconds. 
  
}

