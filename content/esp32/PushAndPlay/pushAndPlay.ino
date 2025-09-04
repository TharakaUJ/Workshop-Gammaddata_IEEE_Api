#define BUZZER_PIN  13
#define BUTTON_PIN  4    // Changed to GPIO 4 for consistent connectivity

// Musical note frequencies (Hz)
#define C4  262
#define D4  294
#define E4  330
#define F4  349
#define G4  392
#define A4  440
#define B4  494
#define C5  523

// Simple melodies (frequency in Hz, duration in ms)
int melody1[][2] = {
    {C4, 200}, {D4, 200}, {E4, 200}, {F4, 200}, {G4, 400}  // C major scale up
};

int melody2[][2] = {
    {G4, 200}, {F4, 200}, {E4, 200}, {D4, 200}, {C4, 400}  // C major scale down
};

// Happy Birthday melody
int happyBirthday[][2] = {
    {C4, 200}, {C4, 200}, {D4, 400}, {C4, 400}, {F4, 400}, {E4, 800},
    {C4, 200}, {C4, 200}, {D4, 400}, {C4, 400}, {G4, 400}, {F4, 800},
    {C4, 200}, {C4, 200}, {C5, 400}, {A4, 400}, {F4, 400}, {E4, 400}, {D4, 800},
    {B4, 200}, {B4, 200}, {A4, 400}, {F4, 400}, {G4, 400}, {F4, 800}
};

// Twinkle Twinkle Little Star melody
int twinkleTwinkle[][2] = {
    {C4, 400}, {C4, 400}, {G4, 400}, {G4, 400}, {A4, 400}, {A4, 400}, {G4, 800},
    {F4, 400}, {F4, 400}, {E4, 400}, {E4, 400}, {D4, 400}, {D4, 400}, {C4, 800},
    {G4, 400}, {G4, 400}, {F4, 400}, {F4, 400}, {E4, 400}, {E4, 400}, {D4, 800},
    {G4, 400}, {G4, 400}, {F4, 400}, {F4, 400}, {E4, 400}, {E4, 400}, {D4, 800},
    {C4, 400}, {C4, 400}, {G4, 400}, {G4, 400}, {A4, 400}, {A4, 400}, {G4, 800},
    {F4, 400}, {F4, 400}, {E4, 400}, {E4, 400}, {D4, 400}, {D4, 400}, {C4, 800}
};

int* melodies[] = {(int*)melody1, (int*)melody2, (int*)happyBirthday, (int*)twinkleTwinkle};
int melodyLengths[] = {5, 5, 24, 48};
String melodyNames[] = {"Scale Up", "Scale Down", "Happy Birthday", "Twinkle Twinkle"};
int currentMelody = 0;
bool skipRequested = false;

void IRAM_ATTR handleButton() {
    skipRequested = true;
}

void setup() {
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);  // Use internal pull-up resistor
    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), handleButton, FALLING);
    
    Serial.begin(115200);
    Serial.println("🎵 Push and Play Music Box Ready!");
    Serial.println("Press button to skip to next melody");
    Serial.println("Available melodies:");
    for (int i = 0; i < 4; i++) {
        Serial.print(i + 1);
        Serial.print(". ");
        Serial.println(melodyNames[i]);
    }
    Serial.println();
}

void playMelody(int melody[][2], int length) {
    for (int i = 0; i < length; i++) {
        if (skipRequested) break;
        tone(BUZZER_PIN, melody[i][0], melody[i][1]);
        delay(melody[i][1] + 50);
        noTone(BUZZER_PIN);
    }
}

void loop() {
    skipRequested = false;
    
    Serial.print("🎼 Now playing: ");
    Serial.println(melodyNames[currentMelody]);
    
    playMelody((int(*)[2])melodies[currentMelody], melodyLengths[currentMelody]);
    
    if (skipRequested) {
        Serial.println("⏭️  Skipped by button press!");
    } else {
        Serial.println("✅ Melody completed!");
    }
    
    currentMelody = (currentMelody + 1) % (sizeof(melodies) / sizeof(melodies[0]));
    delay(1000); // Pause before next melody
}