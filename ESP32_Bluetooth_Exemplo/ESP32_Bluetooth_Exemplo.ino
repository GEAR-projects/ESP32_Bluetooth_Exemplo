// This example code is in the Public Domain
// By Evandro Copercini - 2018
// 
// Modificado por Célio Benjamim 
// para o GEAR - 2025
// 
// Esse exemplo cria uma ponte entre o Bluetooth Serial e o Clássico (SPP) 

#include "BluetoothSerial.h"

#define NOME_DISPOSITIVO "GEAR_BT_seunome"

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin(NOME_DISPOSITIVO);

  Serial.print(NOME_DISPOSITIVO); Serial.println(" iniciado");
}

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
  delay(20);
}
