#include <SPI.h>//송신
#include <nRF24L01.h>
#include <RF24.h>

#define trig 4
#define echo 2


RF24 radio(7, 8); // CE, SCN
const byte address[6] = "00001";
void setup() {
radio.begin();
radio.openWritingPipe(address);
radio.setPALevel(RF24_PA_MIN);
radio.stopListening();
Serial.begin(9600);

  Serial.begin (9600);              // 시리얼 모니터를 사용하기 위해 보드레이트를 9600으로 설정합니다.
  pinMode(trig, OUTPUT);   // trigPin 핀을 출력핀으로 설정합니다.
  pinMode(echo, INPUT);    // echoPin 핀을 입력핀으로 설정합니다.

}
void loop() {

  long duration, distance;                   // 각 변수를 선언합니다.
  digitalWrite(trig, LOW);                 // trigPin에 LOW를 출력하고
  delayMicroseconds(2);                    // 2 마이크로초가 지나면
  digitalWrite(trig, HIGH);                // trigPin에 HIGH를 출력합니다.
  delayMicroseconds(10);                  // trigPin을 10마이크로초 동안 기다렸다가
  digitalWrite(trig, LOW);                // trigPin에 LOW를 출력합니다.
  duration = pulseIn(echo, HIGH);   // echoPin핀에서 펄스값을 받아옵니다.
distance = duration * 17 / 1000;          //  duration을 연산하여 센싱한 거리값을 distance에 저장합니다.



  if (distance >= 200 || distance <= 0)       // 거리가 200cm가 넘거나 0보다 작으면
  {
    Serial.println(distance);   // 에러를 출력합니다.
  }
  else                                                    // 거리가 200cm가 넘지 않거나 0보다 작지 않으면
  {
    Serial.print(distance);                         // distance를 시리얼 모니터에 출력합니다.
    Serial.println(" cm");                           // cm를 출력하고 줄을 넘깁니다.                                                           // distance가 10이면 10 cm로 출력됩니다
  }
  delay(500); 
       
int x=distance;
if(x<20){
radio.write(&x, sizeof(x));
delay(100); }}
