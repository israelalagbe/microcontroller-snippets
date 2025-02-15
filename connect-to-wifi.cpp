/*
* @author israelalagbe
* Code snippet for connecting to wifi using supported microcontrollers such as ESP8266, ESP32 using Arduino IDE
*/
#include <Arduino.h>

#if defined(ESP8266)
  #include <ESP8266WiFi.h>  // Include library for ESP8266 microcontroller
#elif defined(ESP32)
  #include <WiFi.h>         // Include library for ESP32 micro controller
#else
  #error "Unsupported board selected!"
#endif


const char* ssid = "wifi name";         
const char* password = "wifi password";

void setup() {
  Serial.begin(115200);  // Start the Serial Monitor

  while(!Serial);

  delay(2000);

  Serial.println("Connecting to Wi-Fi...");
  WiFi.begin(ssid, password);  // Connect to the Wi-Fi network
  
  Serial.print("Connecting to Wireless");

  // Wait until the chip is connected to Wi-Fi
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected to Wi-Fi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());  // Print the local IP address of the device. Not that any device on this network can access this IP
}

void loop() {
  
}