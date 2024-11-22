#include <SPI.h>
#include <LoRa.h>

#define SS 8      // Pin NSS (Chip Select)
#define RST 9     // Pin Reset
#define DIO0 2    // Pin DIO0 para interrupciones

void setup() {
  Serial.begin(9600);
  while (!Serial);

  // Configura los pines del módulo LoRa
  LoRa.setPins(SS, RST, DIO0);

  // Inicializa LoRa
  Serial.println("Inicializando LoRa...");
  if (!LoRa.begin(915E6)) {  // Configura la frecuencia a 915 MHz
    Serial.println("Error al inicializar LoRa");
    while (1);
  }
  Serial.println("LoRa inicializado.");
}

void loop() {
  Serial.println("Enviando mensaje...");
  LoRa.beginPacket();
  LoRa.print("Hola desde LoRa Radio Node");
  LoRa.endPacket();
  delay(2000);  // Enviar cada 2 segundos
}