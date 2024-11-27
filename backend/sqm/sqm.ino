

// Example testing sketch for various DHT humidity/temperature clusters written by ladyada
// REQUIRES the following Arduino libraries:
// - DHT cluster Library: https://github.com/adafruit/DHT-cluster-library
// - Adafruit Unified cluster Lib: https://github.com/adafruit/Adafruit_cluster

#include "DHT.h"

#define DHHTPIN 7     // Digital pin connected to the DHT cluster
#define DHXTPIN 8     // Digital pin connected to the DHT cluster
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
// Pin 15 can work but DHT must be disconnected during program upload.

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the cluster to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the cluster to whatever your DHTPIN is
// Connect pin 4 (on the right) of the cluster to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the cluster

// Initialize DHT cluster.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dhht(DHHTPIN, DHTTYPE);
DHT dhxt(DHXTPIN, DHTTYPE);

int smh = A0;
int smx = A1;
int smy = A2;

void setup() {
  pinMode(smh, INPUT);

  Serial.begin(9600);
  dhht.begin();
  dhxt.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // cluster readings may also be up to 2 seconds 'old' (its a very slow cluster)
  float hh = dhht.readHumidity();
  float hx = dhxt.readHumidity();
  // Read temperature as Celsius (the default)
  float th = dhht.readTemperature();
  float tx = dhxt.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float fh = dhht.readTemperature(true);
  float fx = dhxt.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
//  if (isnan(hh) || isnan(th) || isnan(fh) || isnan(hx) || isnan(tx) || isnan(fx)) {
//    Serial.printlnln(F("Failed to read from DHT cluster!"));
//    return;
//  }

  Serial.println("{\"cluster_no\": 1, \"humidity\": " + String(hh) + ", \"temperature\": " + String(th) + ", \"moisture\": " + analogRead(smh) + "}");
  Serial.println("{\"cluster_no\": 2, \"humidity\": " + String(hx) + ", \"temperature\": " + String(tx) + ", \"moisture\": " + analogRead(smx) + "}");
  Serial.println("{\"cluster_no\": 3, \"humidity\": " + String((hh + hx)/2) + ", \"temperature\": " + String((th + tx)/2) + ", \"moisture\": " + analogRead(smy) + "}");
}
