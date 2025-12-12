// DRV8833 / TB6612 testcode

// --- Motor A ---
const int AIN1 = 16;   // AIN1
const int AIN2 = 10;   // AIN2

// --- Motor B ---
const int BIN1 = 5;    // BIN1
const int BIN2 = 9;    // BIN2

// Standby pin
const int STBY = 7;    // STBY

void setup() {
  // Pin modes instellen
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  pinMode(STBY, OUTPUT);

  // Driver uit standby halen
  digitalWrite(STBY, HIGH);

  Serial.begin(9600);
  Serial.println("DRV8833 test start");
}

void loop() {
  Serial.println("Motoren vooruit");
  forward();
  delay(1000);

  Serial.println("Stop");
  stopMotors();
  delay(1000);

  Serial.println("Motoren achteruit");
  backward();
  delay(1000);

  Serial.println("Stop");
  stopMotors();
  delay(1000);
}

// --- Functies ---

void forward() {
  // Motor A vooruit
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);

  // Motor B vooruit
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
}

void backward() {
  // Motor A achteruit
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);

  // Motor B achteruit
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
}

void stopMotors() {
  // Beide motoren uit
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
}
