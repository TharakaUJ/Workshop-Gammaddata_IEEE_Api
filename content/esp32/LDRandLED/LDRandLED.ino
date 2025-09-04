#define LDR_PIN 25      // Analog pin connected to LDR
#define LED_PIN 13      // Digital pin connected to LED

const int threshold = 500; // Adjust this value based on your environment

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(LDR_PIN, INPUT);
    Serial.begin(9600);
}

void loop() {
    int ldrValue = analogRead(LDR_PIN);
    Serial.println(ldrValue);

    if (ldrValue < threshold) {
        digitalWrite(LED_PIN, HIGH); // Turn LED ON if it's dark
    } else {
        digitalWrite(LED_PIN, LOW);  // Turn LED OFF if it's bright
    }

    delay(100);
}