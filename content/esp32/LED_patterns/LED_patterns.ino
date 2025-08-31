#define LED_PIN 2        // Change to your LED pin
#define NUM_LEDS 8       // Number of LEDs in your pattern

int ledPins[NUM_LEDS] = {2, 4, 5, 18, 19, 21, 22, 23}; // Example pins for multiple LEDs

void setup() {
    for (int i = 0; i < NUM_LEDS; i++) {
        pinMode(ledPins[i], OUTPUT);
        digitalWrite(ledPins[i], LOW);
    }
}

void loop() {
    // Pattern 1: Chase
    for (int i = 0; i < NUM_LEDS; i++) {
        digitalWrite(ledPins[i], HIGH);
        delay(100);
        digitalWrite(ledPins[i], LOW);
    }

    // Pattern 2: Blink all
    for (int i = 0; i < NUM_LEDS; i++) {
        digitalWrite(ledPins[i], HIGH);
    }
    delay(300);
    for (int i = 0; i < NUM_LEDS; i++) {
        digitalWrite(ledPins[i], LOW);
    }
    delay(300);

    // Pattern 3: Alternate
    for (int i = 0; i < NUM_LEDS; i++) {
        digitalWrite(ledPins[i], (i % 2 == 0) ? HIGH : LOW);
    }
    delay(300);
    for (int i = 0; i < NUM_LEDS; i++) {
        digitalWrite(ledPins[i], (i % 2 == 1) ? HIGH : LOW);
    }
    delay(300);
}