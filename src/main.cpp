#include <Arduino.h>
#include <DHT.h>

#define pinTempreture 32
#define DHTtype DHT22

DHT dht(pinTempreture, DHTtype);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float Temperature;
  float Humidity;

   // Vérification si données bien reçues
  if (isnan(Humidity) || isnan(Temperature)) {
    Serial.println("Aucune valeur retournée par le DHT22. Est-il bien branché ?");
    delay(2000);
    return;         
  }

  Temperature=dht.readTemperature();
  Serial.print("today's temperature:");
  Serial.println(Temperature);

  Humidity=dht.readHumidity();
  Serial.print("today's humidity :");
  Serial.println(Humidity);

  delay(1000);
}
