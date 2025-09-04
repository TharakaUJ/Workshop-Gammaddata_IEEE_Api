#define LDR_PIN 4  // Analog pin connected to LDR voltage divider

void setup() {
    Serial.begin(115200);
    Serial.println("LDR Light Sensor Ready!");
    Serial.println("Circuit: 3.3V -> LDR -> GPIO4 -> 10kΩ -> GND");
    Serial.println("Bright light = Low values, Dark = High values");
    Serial.println();
}

void loop() {
    int ldrValue = analogRead(LDR_PIN); // Read LDR value (0-4095)
    
    // Convert to percentage (0-100%)
    float lightPercent = map(ldrValue, 0, 4095, 100, 0); // Invert: low value = bright
    
    Serial.print("LDR Raw Value: ");
    Serial.print(ldrValue);
    Serial.print(" | Light Level: ");
    Serial.print(lightPercent);
    Serial.print("% | Status: ");
    
    // Determine light condition
    if (ldrValue < 1000) {
        Serial.println("☀️ Very Bright");
    } else if (ldrValue < 2000) {
        Serial.println("🌤️ Bright");
    } else if (ldrValue < 3000) {
        Serial.println("🌥️ Dim");
    } else {
        Serial.println("🌑 Dark");
    }
    
    delay(500); // Wait half a second
}