#include <Servo.h>

Servo monServo;
int pinServo = 4;      // Broche du signal du servomoteur

void setup() {
  monServo.attach(pinServo);    // Attacher le servomoteur à la broche 9
  monServo.writeMicroseconds(1500); // Arrêt du servomoteur
}

void loop() {
  
  monServo.writeMicroseconds(2500); 
  
  // Aucun bouton appuyé → arrêt
  //monServo.writeMicroseconds(1500);
  
}