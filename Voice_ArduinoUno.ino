#include <SoftwareSerial.h>
SoftwareSerial bluetooth(7, 6); // RX, TX

#define MLa 8     // Left motor A
#define MLb 9     // Left motor B
#define MRa 10    // Right motor A
#define MRb 11    // Right motor B

String command = "";

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

  pinMode(MLa, OUTPUT);
  pinMode(MLb, OUTPUT);
  pinMode(MRa, OUTPUT);
  pinMode(MRb, OUTPUT);

  stopMotors(); // Start with motors stopped
}

void loop() {
  if (bluetooth.available()) {
    command = bluetooth.readStringUntil('\n');
    command.trim();
    command.toLowerCase();
    Serial.println("Command received: " + command);

    // Stop before executing next action
    stopMotors();

    if (command.indexOf("front") != -1 || command.indexOf("forward") != -1 || command.indexOf("advance") != -1) {
      moveForward();
    } else if (command.indexOf("back") != -1 || command.indexOf("reverse") != -1) {
      moveBackward();
    } else if (command.indexOf("left") != -1) {
      turnLeft();  // Fixed left turn
    } else if (command.indexOf("right") != -1) {
      turnRight(); // Fixed right turn
    } else if (command.indexOf("stop") != -1) {
      stopMotors();
    } else {
      Serial.println("Unknown command");
    }
  }
}

// === Motor control functions ===

void moveForward() {
  digitalWrite(MLa, LOW);
  digitalWrite(MLb, HIGH);
  digitalWrite(MRa, LOW);
  digitalWrite(MRb, HIGH);
}

void moveBackward() {
  digitalWrite(MLa, HIGH);
  digitalWrite(MLb, LOW);
  digitalWrite(MRa, HIGH);
  digitalWrite(MRb, LOW);
}

void turnLeft() {
  // Left motors run forward, right motors stop
  digitalWrite(MLa, LOW);
  digitalWrite(MLb, HIGH);
  digitalWrite(MRa, LOW);
  digitalWrite(MRb, LOW);
}

void turnRight() {
  // Right motors run forward, left motors stop
  digitalWrite(MLa, LOW);
  digitalWrite(MLb, LOW);
  digitalWrite(MRa, LOW);
  digitalWrite(MRb, HIGH);
}

void stopMotors() {
  digitalWrite(MLa, LOW);
  digitalWrite(MLb, LOW);
  digitalWrite(MRa, LOW);
  digitalWrite(MRb, LOW);
}
