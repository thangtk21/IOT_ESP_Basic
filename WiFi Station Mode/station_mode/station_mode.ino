#include <ESP8266WiFi.h>
const char* ssid = "DIAMOND ELECTRIC VN GUEST";
const char* password = "diamond12345";

void setup()
{
  Serial.begin(115200);       // transmit to PC
  WiFi.begin(ssid,password);  // connect esp to wifi
  Serial.print("\nConnecting to ");
  Serial.print(ssid);

  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  
  Serial.println("\nConnected");
  Serial.print("IP Address of ESP: ");
  Serial.print(WiFi.localIP());
}
void loop(){}
