#include <ESP8266WiFi.h>            
const char *ssid = "AOE_TTC";     // Tên của mạng WiFi muốn đặt
const char *password = "88888888";     // Mật khẩu của mạng WiFi. Bỏ trống nếu không muốn đặt mật khẩu.
void setup() {
  Serial.begin(115200);             
  WiFi.softAP(ssid, password);      // Khởi tạo chức năng Access Point
  Serial.print("Access Point: ");
  Serial.print(ssid);
  Serial.println(" started");
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());  // Gởi địa chỉ IP đến máy tinh
}
void loop() {}
