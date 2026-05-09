// Inverter Control Code for Arduino Nano
// Target Frequency: 50Hz (Period = 20ms)

const int mosfet1 = 9;  // Pin D9
const int mosfet2 = 10; // Pin D10

void setup() {
  pinMode(mosfet1, OUTPUT);
  pinMode(mosfet2, OUTPUT);
  
  // Ensure both are off at start
  digitalWrite(mosfet1, LOW);
  digitalWrite(mosfet2, LOW);
}

void loop() {
  // Phase 1: Turn on MOSFET 1
  digitalWrite(mosfet1, HIGH);
  delay(9); // On for 9ms
  
  // Dead Time: Both OFF to prevent short circuit
  digitalWrite(mosfet1, LOW);
  delay(1); // 1ms gap
  
  // Phase 2: Turn on MOSFET 2
  digitalWrite(mosfet2, HIGH);
  delay(9); // On for 9ms
  
  // Dead Time: Both OFF
  digitalWrite(mosfet2, LOW);
  delay(1); // 1ms gap
  
  // Total cycle = 9 + 1 + 9 + 1 = 20ms (50Hz)
}