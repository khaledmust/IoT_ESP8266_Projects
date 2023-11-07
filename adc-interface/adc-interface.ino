/************************************************************
*   Author: Khaled Mustafa                                  *
*   Date: 2023-11-07                                        *
*   Board: NodeMCU 1.0                                      *
*   Description: Read for the ADC.                          *
*************************************************************/

float adc_output = 0;

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
  adc_output = analogRead(A0);

  // Printing digital value.  
  Serial.print("Digital value: ");
  Serial.println(adc_output);

  // Printing analog value.
  // 1023           --- 3.3v
  // Digital value  --- Vx
  Serial.print("Analog value: ");
  Serial.println(3.3 * adc_output / 1023);

  delay(1000);
}
