#include "UbidotsMicroESP8266.h"

#define DEVICE  "esp"                                        // Put here your Ubidots device label
#define VARIABLE  "button"                                   // Put here your Ubidots variable label
#define TOKEN  "BBFF-gy8Mi9E7EKZxjBF8KdPfQPbM2M31Xp"         // Put here your Ubidots 

#define WIFISSID "No One"                                    // Put here your Wi-Fi SSID
#define PASSWORD "nopassword"                                // Put here your Wi-Fi password

Ubidots client(TOKEN);

void setup() 
{
    // put your setup code here, to run once:

    Serial.begin(115200);
    
    client.wifiConnection(WIFISSID, PASSWORD);
    
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, 1);
    //client.setDebug(true); // Uncomment this line to set DEBUG on

}

void loop() 
{
    // put your main code here, to run repeatedly:

    float value = client.getValueWithDevice(DEVICE, VARIABLE);
    
    if (value != ERROR_VALUE)
    {
      Serial.print(F("value obtained: "));
      Serial.println(value);
    }
    else
    {
      Serial.println(F("Error getting value"));
    }
    delay(1000);
}

}
