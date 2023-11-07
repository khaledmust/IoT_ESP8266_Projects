/************************************************************
*   Author: Khaled Mustafa                                  *
*   Date: 2023-11-07                                        *
*   Board: NodeMCU 1.0                                      *
*   Description: Blink both the ESP and NodeMCU             *
*                 built-in LED.                             *
*************************************************************/

#define ESP_LED   D4
#define NODE_LED  D0

void setup() {
  pinMode(ESP_LED, OUTPUT);
  pinMode(NODE_LED, OUTPUT);
}

void loop() {
  // Turn off the LEDs. (This is because both the LEDs are active low.)
  digitalWrite(ESP_LED, HIGH);
  digitalWrite(NODE_LED, HIGH);
  delay(1000);

  // Turn on the LEDs.
  digitalWrite(ESP_LED, LOW);
  digitalWrite(NODE_LED, LOW);
  delay(1000);
}
