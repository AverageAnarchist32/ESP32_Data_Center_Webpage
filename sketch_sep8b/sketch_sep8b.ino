#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebSrv.h>

// Constants won't change
#define LIGHT_SENSOR_PIN  35  // ESP32 pin GPIO35 (ADC1) connected to the light sensor
#define LED_PIN           27  // ESP32 pin GPIO27 connected to the LED
#define ANALOG_THRESHOLD  3000 // Threshold value for the light sensor

// WiFi credentials
const char* ssid = "TKZ-10";
const char* password = "Careful11";

// Create an instance of the web server
AsyncWebServer server(80);

void setup() {
  // Initialize serial communication
  Serial.begin(115200);

  // Connect to Wi-Fi
  connectToWiFi();

  // Initialize the LED pin as an output
  pinMode(LED_PIN, OUTPUT);

  // Route for serving sensor data
  server.on("/data", HTTP_GET, [](AsyncWebServerRequest *request){
    // Read the analog value from the light sensor
    int analogValue = analogRead(LIGHT_SENSOR_PIN);

    // Create a JSON response
    String response = "{\"analogValue\":" + String(analogValue) + ",";
    response += "\"ledStatus\":\"" + String(digitalRead(LED_PIN) ? "On" : "Off") + "\"}";

    request->send(200, "application/json", response);
  });

  // Start the server
  server.begin();
}

void loop() {
  // Read the analog value from the light sensor
  int analogValue = analogRead(LIGHT_SENSOR_PIN);

  // Update the LED based on the analog value and threshold
  if (analogValue < ANALOG_THRESHOLD)
    digitalWrite(LED_PIN, HIGH); // Turn on the LED if the analog value is below the threshold
  else
    digitalWrite(LED_PIN, LOW);  // Turn off the LED if the analog value is above or equal to the threshold

}

void connectToWiFi() {
  // Connect to Wi-Fi using the provided SSID and password
  WiFi.begin(ssid, password);

  Serial.print("Connecting to ");
  Serial.println(ssid);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Connected to WiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

