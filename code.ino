// Automatic Water Dispenser using Flow Sensor and Button
// Board: Arduino Nano

volatile int flowPulseCount = 0;
float calibrationFactor = 4.5;  // Change based on your sensor datasheet

const int flowSensorPin = 2;     // Must be interrupt-capable pin (D2 on Nano)
const int pumpPin = 3;           // Pin to control relay or transistor
const int buttonPin = 4;         // Push button for manual dispensing

unsigned long oldTime = 0;
float flowRate;
float volume;                    // mL

void setup() {
  pinMode(flowSensorPin, INPUT_PULLUP);
  pinMode(pumpPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(flowSensorPin), pulseCounter, RISING);

  Serial.begin(9600);
  digitalWrite(pumpPin, LOW);  // Make sure pump is off
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    Serial.println("Dispensing started...");

    flowPulseCount = 0;
    volume = 0;

    digitalWrite(pumpPin, HIGH);  // Turn on pump

    while (volume < 250) {  // Target volume in milliliters
      if ((millis() - oldTime) > 1000) { // Every second
        detachInterrupt(digitalPinToInterrupt(flowSensorPin));

        flowRate = ((1000.0 / (millis() - oldTime)) * flowPulseCount) / calibrationFactor;
        oldTime = millis();

        volume += (flowRate / 60) * 1000; // mL in 1 second
        Serial.print("Volume: ");
        Serial.print(volume);
        Serial.println(" mL");

        flowPulseCount = 0;
        attachInterrupt(digitalPinToInterrupt(flowSensorPin), pulseCounter, RISING);
      }
    }

    digitalWrite(pumpPin, LOW);  // Stop pump
    Serial.println("Target volume reached. Dispensing stopped.");
    delay(2000);  // Prevent button bouncing
  }
}

void pulseCounter() {
  flowPulseCount++;
}
