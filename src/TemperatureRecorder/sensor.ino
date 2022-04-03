#include <OneWire.h>

OneWire sensor(4);

unsigned long lastUpdate = 0;
int updateInterval = 10000; // 10 seconds

void temperatureUpdate() {
  if (millis() - lastUpdate < updateInterval) return;

  lastUpdate += updateInterval;

  String data = String(lastUpdate / 1000) + ',' + getTemperature();

  writeData(data);
}

float getTemperature() {
  byte data[2];

  sensor.reset();
  sensor.write(0xCC);
  sensor.write(0x44);
  
  delay(1000);
  
  sensor.reset();
  sensor.write(0xCC); 
  sensor.write(0xBE);

  data[0] = sensor.read();
  data[1] = sensor.read();
  
  float temperature = ((data[1] << 8) | data[0]) * 0.0625;

  return ((data[1] << 8) | data[0]) * 0.0625;
}
