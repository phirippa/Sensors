#include "DHT.h"
#define DHTPIN  D4     
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(1000);                      // DHT11 max sampling rate 1Hz
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t) ) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print("Humidity: "); Serial.print(h); Serial.print("[%]\t");
  Serial.print("Temperature: "); Serial.print(t); Serial.println("[*C]");
}
