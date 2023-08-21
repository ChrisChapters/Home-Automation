#define BLYNK_TEMPLATE_ID "TMPL3nDEzFFYz"
#define BLYNK_TEMPLATE_NAME "NodeMCU"
#define BLYNK_AUTH_TOKEN "ThCDm_0LnnphUI9oaACvOi8Lq1xrio92"
 
#define BLYNK_PRINT Serial
#include <gpio.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
 
char auth[] = BLYNK_AUTH_TOKEN;
 
char ssid[] = "Samsung";
char pass[] = "12345667";

 
 void setup()
 {
   Serial.begin(115200);
   Blynk.begin(BLYNK_AUTH_TOKEN,ssid,pass);

   pinMode(D1,OUTPUT);
 }

BLYNK_WRITE(V1)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D1, LOW);
    Serial.println("LED ON");
  }
  if(value == 0)
  {
     digitalWrite(D1, HIGH);  
     Serial.println("LED OFF");
  }
}
  
void loop()
{
  Blynk.run();
}
