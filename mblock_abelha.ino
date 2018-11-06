// generated by mBlock5 for <your product>
// codes make you happy

#include <Servo.h>
#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

float A0_LDR = 0;
float Conquistas = 0;
float A1_LM35_Temp = 0;
float D12_sonar = 0;
float D6_Buzzer = 0;
float PIR = 0;
float Interruptor = 0;

Servo servo_10;
void config (){
  Serial.println("Teste de Medições");
  servo_10.write(180);
  analogWrite(9,0);
  tone(6,262,0.25*1000);
  _delay(1);

}
void leds (){
  _delay(0.5);
  analogWrite(9,50);
  digitalWrite(13,1);
  _delay(0.5);
  digitalWrite(13,0);
  analogWrite(9,255);

}
float getDistance(int trig,int echo){
    pinMode(trig,OUTPUT);
    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    pinMode(echo, INPUT);
    return pulseIn(echo,HIGH,30000)/58.0;
}
void medir (){
  A0_LDR = abs(analogRead(A0+0));
  Serial.println(String("LDR: ") + String(A0_LDR));
  A1_LM35_Temp = abs((analogRead(A0+1) * 500) / 1024);
  Serial.println(String("Temp: ") + String(A1_LM35_Temp));
  D12_sonar = getDistance(12,12);
  Serial.println(String("Dist: ") + String(D12_sonar));

}

void _delay(float seconds) {
  long endTime = millis() + seconds * 1000;
  while(millis() < endTime) _loop();
}

void setup() {
  pinMode(3,INPUT);
  pinMode(2,INPUT);
  pinMode(6,INPUT);
  Serial.begin(115200);
  servo_10.attach(10);
  pinMode(9,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(A0+0,INPUT);
  pinMode(A0+1,INPUT);
  config();

}

void _loop() {
}

void loop() {
  leds();
  medir();
  PIR = digitalRead(3);
  Interruptor = digitalRead(2);
  D6_Buzzer = digitalRead(6);
  Serial.println(String("PIR: ") + String(digitalRead(3)));
  if(PIR == 1.000000){
      for(int count=0;count<3;count++){
          tone(6,82,0.25*1000);
          tone(6,87,0.25*1000);
          _delay(0.5);
      }

  }
  Serial.println(String("Int:") + String(digitalRead(2)));
  if(Interruptor == 1.000000){
      servo_10.write(90);

  }else{
      servo_10.write(0);

  }

  leds();
  medir();
  PIR = digitalRead(3);
  Interruptor = digitalRead(2);
  D6_Buzzer = digitalRead(6);
  Serial.println(String("PIR: ") + String(digitalRead(3)));
  if(PIR == 1.000000){
      for(int count2=0;count2<3;count2++){
          tone(6,82,0.25*1000);
          tone(6,87,0.25*1000);
          _delay(0.5);
      }

  }
  Serial.println(String("Int:") + String(digitalRead(2)));
  if(Interruptor == 1.000000){
      servo_10.write(90);

  }else{
      servo_10.write(0);

  }

  _loop();
}