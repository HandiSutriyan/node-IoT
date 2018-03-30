#include <Arduino.h>
#include <../lib/DHT/DHT.h>
#include <../lib/ArduinoJson/ArduinoJson.h>

DHT dht;
const size_t BUFFER_SIZE = JSON_OBJECT_SIZE(2);
const int DHT_PIN = 2;

int temperature, humidity, newTemperature, newHumidity;

void setup() {
  Serial.begin(9600);
  dht.setup(DHT_PIN);
}

void loop() {
  delay(dht.getMinimumSamplingPeriod());

  // Read temperature and humidity from DHT11
  newTemperature = dht.getTemperature();
  newHumidity = dht.getHumidity();

  // If any of the read parameters has changed
  if (newTemperature != temperature || newHumidity != humidity) {
    // Assign new values to the variables
    temperature = newTemperature;
    humidity = newHumidity;

    // Create a JSON buffer
    DynamicJsonBuffer jsonBuffer(BUFFER_SIZE);
    JsonObject& root = jsonBuffer.createObject();

    // Set JSON object values
    root["temperature"] = temperature;
    root["humidity"] = humidity;

    // Print data to Serial
    root.printTo(Serial);
    Serial.println();
  }
}
