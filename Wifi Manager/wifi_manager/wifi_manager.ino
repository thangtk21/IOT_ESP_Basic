#include <ESP8266WiFi.h>                   // Thư viện dùng để kết nối WiFi của ESP8266
#include <DNSServer.h>                     // Thư viện DNS Server dùng để chuyển hướng tất cả try vấn đến trang web portal
#include <ESP8266WebServer.h>              // Thư viện dùng để chạy web portal server
#include <WiFiManager.h>                   // Thư viện dùng cấu hình WiFiManager

WiFiManager wifiManager; 
void setup() {
  Serial.begin(115200);                    
  wifiManager.resetSettings();
  wifiManager.autoConnect("My home 123","88888888");
  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP());
}
void loop() {}
