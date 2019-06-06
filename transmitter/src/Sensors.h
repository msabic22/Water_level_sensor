#ifndef Sensors_h
#define Sensors_h

#include <Arduino.h>
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <NewPing.h>

#define DHTPIN 3
#define DHTPIN_VCC 4
#define DHTTYPE DHT22

#define TRIGGER_PIN  7
#define ECHO_PIN 8
#define MAX_DISTANCE 400
#define ITERATIONS 3

class SENSORS {
public:
        SENSORS();
        ~SENSORS();
        void DHT_init();
        float readTemp();
        float readHum();
        float readDist(float, float);
        void printTemp(float );
        void printHum(float );
        void printDist(float );
};

#endif
