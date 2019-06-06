#include "Sensors.h"

DHT dht(DHTPIN, DHTTYPE);
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);


SENSORS::SENSORS(){}
SENSORS::~SENSORS(){}

void SENSORS::DHT_init(){
  pinMode(DHTPIN_VCC,OUTPUT);
  digitalWrite(DHTPIN_VCC,LOW);
  Serial.println(F("DHTxx test!"));
  dht.begin();
}

void SENSORS::printHum(float h) {
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F(" %\t"));
}

void SENSORS::printTemp(float t) {
  Serial.print(F("Temperature: "));
  Serial.print(t);
  Serial.println(F(" *C "));
}

void SENSORS::printDist(float d) {
  Serial.print(F("\nDistance: "));
  Serial.print(d);
  Serial.println(F(" cm "));
}

float SENSORS::readTemp() {
  digitalWrite(DHTPIN_VCC, HIGH);

  // Wait at least 2 seconds seconds between measurements.
  unsigned long previousMillis = millis();
  unsigned long currentMillis = millis();
  while (currentMillis - previousMillis <= 2300) {
    // save the last time you read the sensor
    currentMillis = millis();
  }
  return dht.readTemperature();
  digitalWrite(DHTPIN_VCC,LOW);
}

  float SENSORS::readDist(float temp, float hum){
    float ping = 0;
    ping = sonar.ping_median(ITERATIONS);
    ping = ping;


    float distance; // Stores calculated distance in cm
    float soundsp;  // Stores calculated speed of sound in M/S
    float soundcm;  // Stores calculated speed of sound in cm/ms

    soundsp = 331.4 + (0.606 * temp) + (0.0124 * hum);
    soundcm = soundsp / 10000;
    distance = (ping / 2) * soundcm;

    if (distance >= 400 || distance <= 2) {
      Serial.println(F("OOR"));
    }
    return distance;

  }

float SENSORS::readHum() {

  float h = dht.readHumidity();
  digitalWrite(DHTPIN_VCC,LOW);
  return h;

}
