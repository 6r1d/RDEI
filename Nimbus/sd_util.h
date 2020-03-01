#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

const int chipSelect = 10;

// Audio shield has MicroSD MOSI on pin 7, SCK on pin 14  
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

// preset stuff
int presetNumber = -1;

// TODO related to analogValues,
// which is, in turn, related to MUX input pins
float rawVals[20];

File myFile;
String fileNames[8] = {
  "1.txt",
  "2.txt",
  "3.txt",
  "4.txt",
  "5.txt",
  "6.txt",
  "7.txt",
  "8.txt"
};
bool paramLocks[16];

void setSynthParams(int number, float value);

void loadPreset(int number) {
  String currentPreset = fileNames[number];

  myFile = SD.open(currentPreset.c_str());

  if (myFile) {
    for (int i = 0; i < 20; i++) {
      int input = myFile.parseFloat();
      rawVals[i] = input;
      if (i < 16) {
        paramLocks[i] = true;
      }
    }
    // Close the file:
    myFile.close();
    // Set all them params
    for (int i = 0; i < 20; ++i) {
      setSynthParams(i, rawVals[i]);
    }
  } else {
    // If the file didn't open, print an error:
    Serial.println("error opening file");
  }
}

void savePreset(int number) {
  String currentPreset = fileNames[number];
  // Remove File
  if (SD.exists(currentPreset.c_str())) {
    Serial.println("remove the file");
    SD.remove(currentPreset.c_str());
  }
  // open File
  myFile = SD.open(currentPreset.c_str(), FILE_WRITE);
  // if the file opened okay, write to it:
  if (myFile) {
    for (int i = 0; i < 20; ++i) {
      myFile.println(rawVals[i]);
    }
    //  close the file:
    myFile.close();
    Serial.print("wrote to file");
  } else {
    //  if the file didn't open, print an error:
    Serial.println("error opening file");
  }
}
