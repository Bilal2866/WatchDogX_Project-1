const int analogPinV2 = A1;  // The analog pin connected to V2
const int analogPinV3 = A5;  // The analog pin connected to V3
const int ADC_MAX = 1023;     // Maximum ADC value (10-bit ADC)
const float V_MAX = 5.0;      // The reference voltage (5V)

void setup() {
  Serial.begin(9600);  // Start serial communication
}

void loop() {
  
  int sensorValueV2 = analogRead(analogPinV2);  // Read the analog value for V3 
  int sensorValueV3 = analogRead(analogPinV3);  // Read the analog value for V3 
  
  // Converting the sensor values to voltage (0-5V)
  float voltageV2 = (sensorValueV2 / (float)ADC_MAX) * V_MAX;
  float voltageV3 = (sensorValueV3 / (float)ADC_MAX) * V_MAX;
  
  // Print the voltages to the serial monitor
  Serial.print("Voltage at V2 = ");
  Serial.print(voltageV2);
  Serial.println(" V");
  delay(1000);

  Serial.print("Voltage at V3 = ");
  Serial.print(voltageV3);
  Serial.println(" V");
  
  delay(1000);  // 1 second before reading again
}