#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#define led 2
ESP8266WebServer server(80);
char* ssid = "DIAMOND ELECTRIC VN";
char* password = "devietnam@2019#";

void setup()
{
  pinMode(led,OUTPUT);
  Serial.begin(115200);       
  WiFi.begin(ssid,password);  
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(50);
  }
  Serial.print(WiFi.localIP());

  server.on("/",init_handle);
  server.on("/led", HTTP_POST, handleLED); 
  server.begin();
}
void loop()
{
  server.handleClient(); // listen from browse
}
void handleLED() 
{
  digitalWrite(led,!digitalRead(led));  // Thay đổi trạng thái của LED
  server.sendHeader("Location","/");    // Yêu cầu trình duyệt chuyển hướng đến trang chủ
  server.send(303);                     // Status code dành cho việc chuyển hướng trang web
}
void init_handle() 
{
  server.send(200, "text/html", "<form action=\"/led\" method=\"POST\"><input type=\"submit\" value=\"Toggle LED\"></form>");
}
