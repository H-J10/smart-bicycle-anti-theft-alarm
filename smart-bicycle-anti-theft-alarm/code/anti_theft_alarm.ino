// Smart Bicycle Anti-Theft Alarm
// Triggers alarm only if tilted for 5 full seconds

const byte TILT_PIN = 2;
const byte BUZZER_PIN = 8;

unsigned long tiltStartTime = 0;
bool alarmActive = false;

void setup() {
  pinMode(TILT_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
  Serial.begin(9600);
}

void loop() {
  bool tilted = digitalRead(TILT_PIN);

  if (tilted) {
    if (tiltStartTime == 0) tiltStartTime = millis();
    if (millis() - tiltStartTime >= 5000) alarmActive = true;
  } else {
    tiltStartTime = 0;
    alarmActive = false;
  }

  if (alarmActive) {
    digitalWrite(BUZZER_PIN, HIGH);
    Serial.println("ALARM: Bike tilted!");
  } else {
    digitalWrite(BUZZER_PIN, LOW);
    Serial.println("Safe");
  }

  delay(100);
}