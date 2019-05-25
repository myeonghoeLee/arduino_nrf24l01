#include <SPI.h>//송신
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, SCN
const byte address[6] = "00001";
void setup() {
radio.begin();
radio.openWritingPipe(address);
radio.setPALevel(RF24_PA_MIN);
radio.stopListening();
Serial.begin(9600);
pinMode(4,INPUT);
}
void loop() {
int x =digitalRead(4);
radio.write(&x, sizeof(x));
delay(100); }
