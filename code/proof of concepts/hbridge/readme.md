# H-Bridge proof of concept

minimale hard- & software + stappenplan dat aantoont dat 2 motoren onafhankelijk van elkaar kunnen draaien, en (traploos) regelbaar zijn in snelheid en draairichting.

const int AIN1 = 16;
const int AIN2 = 10;

const int BIN1 = 5;
const int BIN2 = 9;

const int STBY = 7;

void setup() {
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(STBY, OUTPUT);
  digitalWrite(STBY, HIGH);
  Serial.begin(9600);
}

void loop() {
  motorA(100);
  motorB(-200);
  delay(2000);

  stopMotors();
  delay(1000);

  motorA(-255);
  motorB(180);
  delay(2000);

  stopMotors();
  delay(1000);

  motorA(120);
  motorB(240);
  delay(2000);

  stopMotors();
  delay(1500);
}

void motorA(int speed) {
  if (speed > 0) {
    digitalWrite(AIN2, LOW);
    analogWrite(AIN1, speed);
  } else if (speed < 0) {
    digitalWrite(AIN1, LOW);
    analogWrite(AIN2, -speed);
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

