// --- Pin Assignments ---
const int hireButton = 2;
const int rejectButton = 3;
const int nextButton = 4;

int ledPins[] = {5, 6, 7, 8, 9};  // Pins for 5 LEDs
int totalLEDs = 5;
int countdownTime = 10000; // 10 seconds in milliseconds

// --- State Variables ---
unsigned long startTime;
bool counting = true;

void setup() {
  Serial.begin(9600);

  // Set button pins as input with internal pull-up
  pinMode(hireButton, INPUT_PULLUP);
  pinMode(rejectButton, INPUT_PULLUP);
  pinMode(nextButton, INPUT_PULLUP);

  // Set LED pins as outputs
  for (int i = 0; i < totalLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW); // make sure LEDs start OFF
  }

  startTime = millis(); // start the countdown
}

void loop() {
  // --- Check Buttons ---
  if (digitalRead(hireButton) == LOW) {
    Serial.println("HIRED");
    resetCountdown();
  }

  if (digitalRead(rejectButton) == LOW) {
    Serial.println("REJECTED");
    resetCountdown();
  }

  if (digitalRead(nextButton) == LOW) {
    Serial.println("NEXT");
    resetCountdown();
  }

  // --- Countdown LED Logic ---
  if (counting) {
    unsigned long elapsed = millis() - startTime;
    int ledsOn = map(elapsed, 0, countdownTime, totalLEDs, 0);

    for (int i = 0; i < totalLEDs; i++) {
      if (i < ledsOn) {
        digitalWrite(ledPins[i], HIGH);
      } else {
        digitalWrite(ledPins[i], LOW);
      }
    }

    if (elapsed >= countdownTime) {
      Serial.println("TIMEOUT");
      resetCountdown();
    }
  }
}

void resetCountdown() {
  for (int i = 0; i < totalLEDs; i++) {
    digitalWrite(ledPins[i], LOW);
  }
  delay(300); // Debounce
  startTime = millis(); // Restart timer
}
