// QTR-8A sensor test voor Arduino
// Aansluitingen volgens jouw beschrijving

// LED op pin 2
const int ledPin = 2;

// Sensor pinnen
const int sensorPins[8] = {A0, A1, A2, A3, 6, 4}; 
// Let op: Jij gaf D6->4, D5->6, D4->A3, D3->A2, D2->A1, D1->A0
// Arduino gebruikt A0-A5 voor analoge pinnen en digitale pinnen voor D4-D6

// Drempelwaarde voor detectie (pas aan indien nodig)
const int threshold = 500;  

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int sensorValues[8];

  // Lees alle sensorwaarden
  for (int i = 0; i < 6; i++) {
    sensorValues[i] = analogRead(sensorPins[i]);
  }

  // Print sensorwaarden naar de Serial Monitor
  Serial.print("Sensor waarden: ");
  for (int i = 0; i < 6; i++) {
    Serial.print(sensorValues[i]);
    Serial.print("\t");
  }
  Serial.println();

  // LED aan/uit afhankelijk van sensor detectie
  bool detected = false;
  for (int i = 0; i < 6; i++) {
    if (sensorValues[i] > threshold) {
      detected = true;
      break;
    }
  }

  if (detected) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(200);
}
