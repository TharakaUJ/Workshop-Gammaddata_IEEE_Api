#define BUZZER_PIN 5  // Change this to the pin your buzzer is connected to

void setup() {
    pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
    digitalWrite(BUZZER_PIN, HIGH); // Turn buzzer ON
    delay(500);                     // Wait 500ms
    digitalWrite(BUZZER_PIN, LOW);  // Turn buzzer OFF
    delay(500);                     // Wait 500ms
}




// #define BUZZER_PIN 5

// int melody[] = {
//     262, 262, 294, 262, 349, 330, // Happy birthday to you
//     262, 262, 294, 262, 392, 349, // Happy birthday to you
//     262, 262, 523, 440, 349, 330, 294, // Happy birthday dear [Name]
//     466, 466, 440, 349, 392, 349 // Happy birthday to you
// };

// int noteDurations[] = {
//     4, 4, 2, 2, 2, 1,
//     4, 4, 2, 2, 2, 1,
//     4, 4, 2, 2, 2, 2, 1,
//     4, 4, 2, 2, 2, 1
// };

// void playHappyBirthday() {
//     for (int i = 0; i < sizeof(melody)/sizeof(melody[0]); i++) {
//         int duration = 500 / noteDurations[i];
//         tone(BUZZER_PIN, melody[i], duration);
//         delay(duration * 1.3);
//         noTone(BUZZER_PIN);
//     }
// }

// void setup() {
//     pinMode(BUZZER_PIN, OUTPUT);
//     playHappyBirthday();
// }

// void loop() {
//     // Nothing here
// }