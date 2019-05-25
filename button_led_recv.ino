#include <SPI.h>//수신
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, SCN
const byte address[6] = "00001";
void setup() {
Serial.begin(9600);
radio.begin();
radio.openReadingPipe(0, address);
radio.setPALevel(RF24_PA_MIN);
radio.startListening();
pinMode(2,OUTPUT);
}
void loop() {
if (radio.available()) {
int x;
radio.read(&x, sizeof(x));
if(x){
digitalWrite(2,LOW);
Serial.println(x);
}
else{
digitalWrite(2,HIGH);
}
}
}
