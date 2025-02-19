/*
* @author israelalagbe
* Code snippet for connecting to Wi-Fi and creating a web server on ESP8266/ESP32 using Arduino IDE
*/

#include <Arduino.h>

#if defined(ESP8266)
  #include <ESP8266WiFi.h>  // Include library for ESP8266 microcontroller
  #include <ESP8266WebServer.h>
  ESP8266WebServer server(80);  // Create a web server on port 80
#elif defined(ESP32)
  #include <WiFi.h>         // Include library for ESP32 microcontroller
  #include <WebServer.h>    
  WebServer server(80);     // Create a web server on port 80
#else
  #error "Unsupported board selected!"
#endif

const char* ssid = "user name";         
const char* password = "your password";

// Function to handle root URL requests
void handleRoot() {
  server.send(200, "text/html", "<h1>Hello, World</h1>");
}

void setup() {
  Serial.begin(115200);  // Start Serial Monitor
  while (!Serial);

  Serial.println("Connecting to Wi-Fi...");
  WiFi.begin(ssid, password);  // Connect to Wi-Fi
  
  Serial.print("Connecting to Wireless");

  // Wait until connected
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected to Wi-Fi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());  // Print local IP which when visited displays the webpage

  // Start Web Server
  server.on("/", handleRoot);  // Define root URL response
  server.begin();
  Serial.println("Web server started.");
}

void loop() {
  server.handleClient();  // Listen for incoming client requests
}