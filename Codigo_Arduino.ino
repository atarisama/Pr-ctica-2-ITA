#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE 9
#define CSN 10
#define boton 2

RF24 radio(CE, CSN);

const byte direccion[6] = "00701";

int dato = 1;

void setup() {

  Serial.begin(9600);
  pinMode(boton, INPUT);

  radio.begin();
  radio.openWritingPipe(direccion);
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening();
}

void loop() {

  int estado = digitalRead(boton);

  if (estado == HIGH) {

    radio.write(&dato, sizeof(dato));

    Serial.println("Mensaje enviado");

    delay(500);
  }

}