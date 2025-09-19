//create constain varriable ledpin
//this led connect GPIO pin 8 of the esp32c3
const int ledPin = 8; 
void setup() {
  pinMode(ledPin, OUTPUT);
}
//Starts serial communication at 115200 baud rate.
// when the led on or off it gone send a text to serial monitor as led on or led off.
void loop() {
  Serial.begin(115200);
  digitalWrite(ledPin, HIGH); 
  Serial.println("LED OFF");
  delay(1000);                     
  digitalWrite(ledPin, LOW); 
  Serial.println("LED ON");  
  delay(5000);                     
}