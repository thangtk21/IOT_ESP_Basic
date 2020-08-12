#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
ESP8266WiFiMulti wfmlt;
void setup() 
{
  Serial.begin(115200);
  wfmlt.addAP("DIAMOND ELECTRIC VN GUEST","diamond12345");
  wfmlt.addAP("Thang RTV","kocopass");
  
  Serial.print("\nConnecting");
  
  while(wfmlt.run() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WiFi.SSID());
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() 
{

}
