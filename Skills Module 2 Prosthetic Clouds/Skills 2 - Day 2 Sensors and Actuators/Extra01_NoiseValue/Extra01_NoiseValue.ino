#include <SPI.h>
#include <SD.h>

const int chipSelect = 4;    // Shield’s CS pin (check your shield)
File dataFile;
String filename = "Data.csv";
String Data = "Entry Number: ";
int loopCount = 1;

void setup() {
  Serial.begin(9600);

  if (!SD.begin(chipSelect)) {
    Serial.println("SD init failed.");
    while (1) { delay(10); }
  }

  SD.remove(filename); // start clean (optional)

  File dataFile = SD.open(filename, FILE_WRITE);
  if (dataFile) {
    dataFile.println("first entry during setup.");
    dataFile.close();
  }
}

void loop() {
  Data.concat(loopCount);

  dataFile = SD.open(filename, FILE_WRITE);
  if (dataFile) {
    dataFile.println(Data);
    dataFile.close();
    Serial.println("New line successfully written: " + Data);
  } else {
    Serial.println("Error opening file.");
  }

  loopCount = loopCount + 1;
  Data = "Entry Number: ";
  delay(1000);
}