// Libraries
#include "DHT.h"
#include "Ultrasonic.h"


// Sensor pins
#define DHTPIN 13     
#define SR04_TIGGER_PIN 4
#define SR04_ECHO_PIN 3
#define SR501_PIN 7


/*
// Digital pin connected to the DHT sensor
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
// Pin 15 can work but DHT must be disconnected during program upload.
*/
// Sensor definitions
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
Ultrasonic ultrasonic(SR04_TIGGER_PIN, SR04_ECHO_PIN);
/*
// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 3 (on the right) of the sensor to GROUND (if your sensor has 3 pins)
// Connect pin 4 (on the right) of the sensor to GROUND and leave the pin 3 EMPTY (if your sensor has 4 pins)
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor
// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
*/

void setup() 
{
// Set up serial communication
  Serial.begin(9600);

// Set up sensors
  dht.begin();
  pinMode(SR501_PIN,INPUT);

// Legend
  Serial.println("Humidity(%) temp(C) distance(cm) motion100 ");
}

void loop() 
{
  // Wait a few seconds between measurements.
  delay(250); //take a reading every 0.25 seconds

  // DHT sensor
  float humidity = dht.readHumidity();
  float tempC = dht.readTemperature();

  Serial.print(humidity);
  Serial.print(" ");
  Serial.print(tempC);
  Serial.print(" ");
  
// HC-SR04
  float distance = ultrasonic.read();
  Serial.print(distance);
  Serial.print(" ");

// HC-SR501
  int motionValue = digitalRead(SR501_PIN);
  Serial.print(motionValue*100);
  Serial.print(" ");
  
  Serial.print("\n");
  
}
