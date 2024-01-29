// Pin configuration
const int buttonPin = 2;  // Pin for the push button
const int ledPins[] = {3, 4, 5, 6, 7, 8, 9, 10}; // Pins for the 8 LEDs

int counter = 0;  // Counter variable to store the current count
int lastButtonState = LOW;  // Variable to store the previous state of the button

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT); // Initialize LEDs as outputs
    digitalWrite(ledPins[i], LOW);  // Initially turn off all LEDs
  }

  // Initialize push button pin
  pinMode(buttonPin, INPUT);

  // Set the initial state of the LEDs
  updateLEDs();
}

void loop() {
  // Read the state of the button
  int buttonState = digitalRead(buttonPin);

  // Check for a button press
  if (buttonState == HIGH && lastButtonState == LOW) {
    // Increment the counter on button press
    counter = (counter + 1) % 256;
    updateLEDs();
  }

  // Update the previous button state
  lastButtonState = buttonState;
}

void updateLEDs() {
  // Update the LEDs based on the binary representation of the counter
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledPins[i], (counter & (1 << i)) ? HIGH : LOW);
  }
}
