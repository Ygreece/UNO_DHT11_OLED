const long BLUETOOTH_BAUD = 9600;

void setup() {
  Serial.begin(BLUETOOTH_BAUD);
  delay(1000);
  Serial.println(F("Bluetooth test started"));
  Serial.println(F("Send text from your phone."));
}

void loop() {
  while (Serial.available() > 0) {
    const char receivedByte = static_cast<char>(Serial.read());
    Serial.print(F("Received: "));
    Serial.println(receivedByte);
  }
}
