#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebSrv.h>
#include <driver/ledc.h>
#include <DHT.h>

// Constants won't change
#define LIGHT_SENSOR_PIN 35    // ESP32 pin GPIO35 (ADC1) connected to the light sensor
#define LED_PIN 14             // ESP32 pin GPIO27 connected to the LED
#define ANALOG_THRESHOLD 3000  // Threshold value for the light sensor
#define PIEZO_BUZZER_PIN 26    // GPIO for piezo buzzer
#define DHTPIN 27              // Define the GPIO pin to which the DHT-11 is connected
#define DHTTYPE DHT11          // Define the type of DHT sensor (DHT11)

DHT dht(DHTPIN, DHTTYPE);  // Initialize the DHT sensor

// WiFi credentials
const char* ssid = "Proxima";
const char* password = "centauri";

// Create an instance of the web server
AsyncWebServer server(80);

/// Define song-related constants and variables
const int songLength = 18;
char notes[] = "cdfda ag cdfdg gf ";
int beats[] = { 1, 1, 1, 1, 1, 1, 4, 4, 2, 1, 1, 1, 1, 1, 1, 4, 4, 2 };
int tempo = 113;
void setup() {

  // Initialize serial communication
  Serial.begin(115200);

  // Connect to Wi-Fi
  connectToWiFi();

  // Initialize the LED pin as an output
  pinMode(LED_PIN, OUTPUT);

  // Initialize the piezo buzzer pin as an output
  pinMode(PIEZO_BUZZER_PIN, OUTPUT);

  // Initialize LEDC timer and channel for the piezo buzzer
  ledcSetup(0, 1000, 8);               // Initialize LEDC channel 0 with a frequency of 1000 Hz and 8-bit depth
  ledcAttachPin(PIEZO_BUZZER_PIN, 0);  // Attach the channel to the piezo buzzer pin

  // Route for serving sensor data
  server.on("/data", HTTP_GET, [](AsyncWebServerRequest* request) {
    // Read the analog value from the light sensor
    int analogValue = analogRead(LIGHT_SENSOR_PIN);


    // Read humidity and temperature from the DHT sensor
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();


    // Create a JSON response
    String response = "{\"analogValue\":" + String(analogValue) + ",";
    response += "\"ledStatus\":\"" + String(digitalRead(LED_PIN) ? "On" : "Off") + "\",";
    response += "\"humidity\":" + String(humidity) + ",";
    response += "\"temperature\":" + String(temperature) + "}";

    request->send(200, "application/json", response);
  });

  // Start the server
  server.begin();
}

// Play a sound when the LED turns on or off
void playBuzzer(int frequency, int duration) {
  tone(PIEZO_BUZZER_PIN, frequency, duration);
  delay(duration);           // Optional delay to control the note duration
  noTone(PIEZO_BUZZER_PIN);  // Turn off the buzzer
}

void loop() {
  // Read the analog value from the light sensor
  int analogValue = analogRead(LIGHT_SENSOR_PIN);

  // Call a function to control the LED and play the song based on the analog value
  controlLED(analogValue);

  float humidity = dht.readHumidity();        // Read humidity value
  float temperature = dht.readTemperature();  // Read temperature value (in Celsius)


  // Read the analog value from the light sensor after updating the LED
  debug();
}
void controlLED(int analogValue) {
  // Update the LED based on the analog value and threshold
  if (analogValue < ANALOG_THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);      // Turn on the LED if the analog value is below the threshold
    playSong();                       // Play the song when the LED turns on
    ledcDetachPin(PIEZO_BUZZER_PIN);  // Deinitialize LEDC channel
  } else {
    digitalWrite(LED_PIN, LOW);       // Turn off the LED if the analog value is above or equal to the threshold
    noTone(PIEZO_BUZZER_PIN);         // Stop the buzzer when the LED turns off
    ledcDetachPin(PIEZO_BUZZER_PIN);  // Deinitialize LEDC channel
  }
}


void debug() {
  int analogValue = analogRead(LIGHT_SENSOR_PIN);
  // Print the analog value to the serial monitor
  Serial.print("Light Sensor Value: ");
  Serial.println(analogValue);
  delay(3000);
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

// Function to play the song
void playSong() {
  int i, duration;
  for (i = 0; i < songLength; i++) {
    duration = beats[i] * tempo;
    if (notes[i] == ' ') {
      delay(duration);
    } else {
      tone(PIEZO_BUZZER_PIN, frequency(notes[i]), duration);
      delay(duration);
    }
    delay(tempo / 10);
  }
}

// Function to get the frequency of a note
int frequency(char note) {
  const int numNotes = 8;
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int frequencies[] = { 262, 294, 330, 349, 392, 440, 494, 523 };

  for (int i = 0; i < numNotes; i++) {
    if (names[i] == note) {
      return frequencies[i];
    }
  }
  return 0;  // Return 0 if the note is not found
}