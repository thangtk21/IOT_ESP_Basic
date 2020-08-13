#include <ESP8266WiFi.h>
#include <WiFiManager.h>
#include <ESP8266WebServer.h>

#define led 2
ESP8266WebServer server(80);
WiFiManager wfmn;
void setup()
{
  Serial.begin(115200);
  pinMode(led,OUTPUT);
  
  wfmn.resetSettings();
  wfmn.autoConnect("TTC Building","88888888");
  Serial.println(WiFi.localIP());

  server.on("/on",onLed);
  server.on("/off",offLed);
  server.begin();
}
void loop()
{
  server.handleClient();
}

void onLed()
{
  server.send(200);
  digitalWrite(led,0);
}
void offLed()
{
  server.send(200,"text/plain","off");
  digitalWrite(led,1);
}
