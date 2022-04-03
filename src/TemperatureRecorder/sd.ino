#include <SPI.h>
#include <SD.h>

const int chipSelect = 8;

File myFile;

int fileIndex = 0;

void initializeSD() {
  if (!SD.begin(chipSelect)) while (1);
  
  genFile();
}

void genFile() {
  while(SD.exists(fileName())) fileIndex++;
  
  myFile = SD.open(fileName(), FILE_WRITE);
  myFile.close();
}

String fileName() {
  return String("data_") + fileIndex + ".csv";
}

void writeData(String data) {
  myFile = SD.open(fileName(), FILE_WRITE);
  
  myFile.println(data);
  
  myFile.close();
}
