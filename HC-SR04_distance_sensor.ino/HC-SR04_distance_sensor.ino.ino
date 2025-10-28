#define TRIG_PIN 7 // Trig pin connected to gp07
#define ECHO_PIN 6  // Echo pin connected to gp06

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Send a 10µs pulse to trigger the sensor
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure the time for the echo to return
  long duration = pulseIn(ECHO_PIN, HIGH);

  // Convert time to distance (speed of sound is ~343 m/s or 0.0343 cm/µs)
  float distance = duration * 0.0343 / 2;

  // Print data for Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Print only the distance value for Serial Plotter
  Serial.println(distance);

  delay(100);  // Short delay for smoother plotting
}