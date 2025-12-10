# H-Bridge proof of concept

minimale hard- & software + stappenplan dat aantoont dat 2 motoren onafhankelijk van elkaar kunnen draaien, en (traploos) regelbaar zijn in snelheid en draairichting.

// DRV8833 / TB6612 testcode met snelheid + onafhankelijke motorbesturing

// --- Motor A ---
const int AIN1 = 16;   // Richting 1 (PWM)
const int AIN2 = 10;   // Richting 2

// --- Motor B ---
const int BIN1 = 5;    // Richting 1 (PWM)
const int BIN2 = 9;    // Richting 2

// Standby pin
const int STBY = 7;

void setup() {
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  pinMode(STBY, OUTPUT);
  digitalWrite(STBY, HIGH); // driver activeren

  Serial.begin(9600);
  Serial.println("Independent DRV8833 motor test");
}

void loop() {

  // --- DEMO 1: Motor A langzaam vooruit, Motor B snel achteruit ---
  Serial.println("A vooruit (langzaam), B achteruit (snel)");

  motorA(100);     // langzaam vooruit
  motorB(-200);    // snel achteruit
  delay(2000);

  stopMotors();
  delay(1000);

  // --- DEMO 2: Motoren omgekeerd ---
  Serial.println("A achteruit, B vooruit");

  motorA(-255);   // max achteruit
  motorB(180);    // matig vooruit
  delay(2000);

  stopMotors();
  delay(1000);

  // --- DEMO 3: Beide vooruit verschillende snelheid ---
  Serial.println("Beide vooruit, verschillende snelheden");

  motorA(120);
  motorB(240);
  delay(2000);

  stopMotors();
  delay(1500);
}

// -------------------------------------------------------------
// MOTORFUNCTIES
// speed: -255 t/m +255
// positief = vooruit, negatief = achteruit
// -------------------------------------------------------------

void motorA(int speed) {
  if (speed > 0) {
    digitalWrite(AIN2, LOW);
    analogWrite(AIN1, speed);   // PWM vooruit
  } else if (speed < 0) {
    digitalWrite(AIN1, LOW);
    analogWrite(AIN2, -speed);  // PWM achteruit
  } else {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);
  }
}

void motorB(int speed) {
  if (speed > 0) {
    digitalWrite(BIN2, LOW);
    analogWrite(BIN1, speed);
  } else if (speed < 0) {
    digitalWrite(BIN1, LOW);
    analogWrite(BIN2, -speed);
  } else {
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, LOW);
  }
}

void stopMotors() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
}
