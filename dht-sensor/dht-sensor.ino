/************************************************************
*   Author: Khaled Mustafa                                  *
*   Date: 2023-11-07                                        *
*   Board: NodeMCU 1.0                                      *
*   Description: Interface with the DHT11 sensor.           *
*************************************************************/

// IMPROVEMENTS: Since we have to use a delay between each read, we could use a non-blocking delay.

#include <DHT.h>

#define DHT_TYPE  11
#define DHT_PIN   D2

DHT dht(DHT_PIN, DHT_TYPE);

float hum = 0;
float temp_c = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // Wait for a time priod before taking the next reading. (This is because the sampling rate of the sensor is 1Hz)
  delay(1000);

  hum = dht.readHumidity();
  temp_c = dht.readTemperature();

  // Checking if the data read is a number.
  // Otherwise print error message, and exit.
  if (isnan(hum) || isnan(temp_c)) {
    Serial.println("Error! Can't read sensor data.");
    return;
  }

  Serial.print("Humidity: ");
  Serial.println(hum);

  Serial.print("Temperature: ");
  Serial.println(temp_c);
}
