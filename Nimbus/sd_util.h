// Audio shield has MOSI on pin 7, SCK on pin 14
  
// SD config
void setupSD() {
  SPI.setMOSI(7);
  SPI.setSCK(14);
  Serial.print("Initializing SD card...");
  if (!SD.begin(chipSelect)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
}
