#define LDR_PIN 4  // Analog pin connected to LDR

void setup() {
    Serial.begin(115200);
    pinMode(LDR_PIN, INPUT);
}

void loop() {
    int ldrValue = analogRead(LDR_PIN); // Read LDR value
    Serial.print("LDR Value: ");
    Serial.println(ldrValue);
    delay(500); // Wait half a second
}