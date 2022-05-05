
// constants won't change
const int TRIG_PIN = 11; // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO_PIN = 10; // Arduino pin connected to Ultrasonic Sensor's ECHO pin
const int LED_PIN  = 8; // Arduino pin connected to LED's pin
const int BUZZER_PIN = 9; // Arduino pin connected to Piezo Buzzer's pin
const int DISTANCE_THRESHOLD = 20; // centimeters

// constants won't change
const int ENA_PIN = 7; // the Arduino pin connected to the EN1 pin L298N
const int IN1_PIN = 6; // the Arduino pin connected to the IN1 pin L298N
const int IN2_PIN = 5; // the Arduino pin connected to the IN2 pin L298N
const int IN3_PIN = 4; // the Arduino pin connected to the IN1 pin L298N
const int IN4_PIN = 3; // the Arduino pin connected to the IN2 pin L298N

// variables will change:
float duration_us, distance_cm;

// the setup function runs once when you press reset or power the board

void setup() {

  // initialize digital pins as outputs.
  Serial.begin (9600);       // initialize serial port
  pinMode(TRIG_PIN, OUTPUT); // set arduino pin to output mode
  pinMode(ECHO_PIN, INPUT);  // set arduino pin to input mode
  pinMode(LED_PIN, OUTPUT);  // set arduino pin to output mode
  pinMode(ENA_PIN, OUTPUT);
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);
}

void loop() {

  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN, HIGH);

  // calculate the distance
  distance_cm = 0.017 * duration_us;

  if (distance_cm < DISTANCE_THRESHOLD) {

    digitalWrite(BUZZER_PIN, HIGH); // turn on Piezo Buzzer
    digitalWrite(LED_PIN, HIGH); // turn on LED

    digitalWrite(IN1_PIN, LOW);   // control motor A spins anti-clockwise
    digitalWrite(IN3_PIN, LOW);  // control motor A spins clockwise

    for (int speed = 255; speed >= 0; speed--) {
      analogWrite(IN2_PIN, speed); // control the speed
      analogWrite(IN4_PIN, speed); // control the speed
      //delay(10);

    }
  }

  if (distance_cm > DISTANCE_THRESHOLD) {

    digitalWrite(BUZZER_PIN, LOW); // turn off Piezo Buzzer
    digitalWrite(LED_PIN, LOW); // turn off LED

    digitalWrite(IN2_PIN, LOW);  // control motor A spins clockwise
    digitalWrite(IN4_PIN, LOW);  // control motor A spins clockwise

    for (int speed = 0; speed <= 255; speed++) {
      analogWrite(IN1_PIN, speed); // control the speed
      analogWrite(IN3_PIN, speed); // control the speed
      //delay(10);
    }

  }
}
