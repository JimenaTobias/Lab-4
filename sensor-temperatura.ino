#include "DHT.h"
#define DHTPIN 5
#define DHTTYPE DHT11
 
DHT dht(DHTPIN, DHTTYPE);
int maxh=0, minh=100, maxt=0, mint=100;
 
void setup() 
{
  Serial.begin(9600); 
  dht.begin();
}
 
void loop() 
{
  int h = dht.readHumidity();
  int t = dht.readTemperature();
 
  if (isnan(t) || isnan(h))
  {
    Serial.println("Fallo al leer del sensor DHT");
  } else {
    Serial.print("Humedad: "); 
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperatura: "); 
    Serial.print(t);
    Serial.println(" *C");
  }
  delay(1000);
}