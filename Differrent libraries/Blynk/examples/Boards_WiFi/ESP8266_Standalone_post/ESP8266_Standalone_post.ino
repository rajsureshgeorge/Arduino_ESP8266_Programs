#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

BlynkTimer timer;
char auth[] = "1e69e8f1dec5400aaed61b9be0455ff0";

char ssid[] = "rpi";
char pass[] = "12345678";

void timer_event()
{
  Blynk.virtualWrite(V1,digitalRead(13));
}
void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, timer_event);
}

void loop()
{
  Blynk.run();
  timer.run();
}
