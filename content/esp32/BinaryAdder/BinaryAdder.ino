const int buttonPin = 4;           // Button input pin (same as PushbuttonTest)
const int ledPins[4] = {5, 18, 19, 21}; // 4 LED output pins for binary display
int pressCount = 0;
bool lastButtonState = HIGH;
bool buttonPressed = false;

void setup() {
    // Initialize LED pins as outputs
    for (int i = 0; i < 4; i++) {
        pinMode(ledPins[i], OUTPUT);
    }
    pinMode(buttonPin, INPUT_PULLUP); // Use internal pull-up resistor
    Serial.begin(115200);
    Serial.println("Binary Counter Ready!");
    Serial.println("Press button to count in binary (0-15)");
    displayBinary(0); // Start with all LEDs off
}

void loop() {
    int reading = digitalRead(buttonPin);

    // Simple button press detection (works better in simulators)
    if (reading == LOW && lastButtonState == HIGH && !buttonPressed) {
        // Button just pressed
        buttonPressed = true;
        pressCount++;
        if (pressCount > 15) pressCount = 0; // 4 bits max (0-15)
        displayBinary(pressCount);
        
        // Print current count and binary representation
        Serial.print("Count: ");
        Serial.print(pressCount);
        Serial.print(" | Binary: ");
        Serial.print(pressCount, BIN);
        Serial.print(" | LEDs: ");
        
        // Show which LEDs are on
        for (int i = 3; i >= 0; i--) {
            Serial.print((pressCount >> i) & 1);
        }
        Serial.println();
        
        delay(200); // Simple debounce delay
    }
    
    if (reading == HIGH && lastButtonState == LOW) {
        // Button released
        buttonPressed = false;
    }
    
    lastButtonState = reading;
    delay(10); // Small delay for stability
}

void displayBinary(int value) {
    for (int i = 0; i < 4; i++) {
        digitalWrite(ledPins[i], (value >> i) & 0x01);
    }
}
