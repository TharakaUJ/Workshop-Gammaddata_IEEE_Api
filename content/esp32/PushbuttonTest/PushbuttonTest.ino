const int buttonPin = 4;     // GPIO pin where pushbutton is connected
const int ledPin = 2;        // GPIO pin where LED is connected (built-in LED on ESP32)

void setup() {
    pinMode(buttonPin, INPUT_PULLUP); // Use internal pull-up resistor
    pinMode(ledPin, OUTPUT);
    Serial.begin(115200);
}

void loop() {
    int buttonState = digitalRead(buttonPin);

    if (buttonState == LOW) { // Button pressed (active low)
        digitalWrite(ledPin, HIGH); // Turn LED on
        Serial.println("Button Pressed");
    } else {
        digitalWrite(ledPin, LOW); // Turn LED off
        Serial.println("Button Released");
    }

    delay(100); // Debounce delay
}