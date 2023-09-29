// Define pins for ultrasonic sensor
const int TRIG_PIN = 7;
const int ECHO_PIN = 6;

// Define pins for LED and buzzer
const int LED_PIN = 13;
const int BUZZER_PIN = 5;

// Define threshold for object detection (in centimeters)
const int OBJECT_THRESHOLD = 50;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // Trigger ultrasonic sensor
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // Read the echo pulse from the sensor
  long duration = pulseIn(ECHO_PIN, HIGH);
  
  // Calculate distance in centimeters
  int distance = duration * 0.034 / 2;
  
  // Print the distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  
  // Check if an object is too close
  if (distance < OBJECT_THRESHOLD) {
    digitalWrite(LED_PIN, HIGH); // Turn on LED
    tone(BUZZER_PIN, 1000); // Play a tone on the buzzer
    delay(500); // Wait for 0.5 seconds
    noTone(BUZZER_PIN); // Stop the buzzer tone
  } else {
    digitalWrite(LED_PIN, LOW); // Turn off LED
    noTone(BUZZER_PIN); // Ensure buzzer is off
  }
  
  delay(1000); // Wait for 1 second before taking another reading
}
