/************************************************************
*   Author: Khaled Mustafa                                  *
*   Date: 2023-11-07                                        *
*   Board: NodeMCU 1.0                                      *
*   Description: Connect to WiFi Router.                    *
*************************************************************/

#include <ESP8266WiFi.h>

// WiFi credentials.
const char ssid[] = "Dr.Mustafa";
const char password[] = "18@november@50";

// Used to count time-out.
char counter = 0;

void setup() {
  Serial.begin(9600);
  Serial.print("Connecting");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    counter++;

    // 20 * 500ms = 10 sec.
    if (counter == 20) {
      break;
    }
  }
  Serial.println();
  
  // Printing messages.
  switch (WiFi.status()) {
    case WL_NO_SSID_AVAIL:
      Serial.println("SSID can't be reached.");
      break;

    case WL_CONNECTED:
      Serial.println("WiFi Connected");
      Serial.println(WiFi.localIP());
      break;

    case WL_CONNECT_FAILED:
      Serial.println("Wrong Password.");
      break;

    default:
      Serial.println("Unknown Error.");
      break;
  }

}

void loop() {
  
}
