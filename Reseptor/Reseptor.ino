#include <LoRa.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);

  // Inicializa LoRa
  Serial.println("Inicializando LoRa...");
  if (!LoRa.begin(915E6)) {  // Configura la frecuencia a 915 MHz
    Serial.println("Error al inicializar LoRa");
    while (1);
  }
  Serial.println("LoRa inicializado.");
}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // Si llega un paquete
    Serial.print("Paquete recibido: ");
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }
    Serial.println();
  }
}