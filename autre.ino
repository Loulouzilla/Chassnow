/************************* Servomoteur ***********************/
#include <Servo.h>  
Servo monServo;

 

/************************* DHT-11 ***********************/
#include "DHT.h" 
#define DHTPIN 9
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

 

/************************* broche capteur ***********************/
int LDR = A0;
int sel = 7;
int presence = 10;
int utilisation = 11;
int lumiere = 12; 
int test = 8;

 

/************************* variables ***********************/
int humidite = 0;
int temperature = 0;
int longueur = 0;
int largeur = 0;

 

void fonctionement () { 
  // Fonction à compléter si nécessaire
}


void arret (){
  digitalWrite(utilisation, LOW);
  monServo.writeMicroseconds(1500);
}

 

void setup (){
  // Capteurs
  dht.begin();
  pinMode(LDR, INPUT);
  pinMode(presence, INPUT);
  pinMode(lumiere, OUTPUT);
  pinMode(utilisation, OUTPUT);
  pinMode(test, INPUT);

 

  Serial.begin(9600);

 

  // Servo
  monServo.attach(sel);             
  monServo.writeMicroseconds(1500); // Arrêt du servomoteur
}

 

void loop (){
  humidite = dht.readHumidity();       
  temperature = dht.readTemperature();

 

  // Lancement si neige (sans capteur couleur)
  if ((temperature <= 0 && humidite > 60) || (digitalRead(test) == 0)) {
    fonctionement();
    Serial.println("SYSTÈME EN MARCHE : Neige détectée !");
    delay(3000);
    arret();
  }

 

  // Gestion de la lumière
  if (analogRead(LDR) > 200) { 
    digitalWrite(lumiere, HIGH);
  } else {
    digitalWrite(lumiere, LOW);
  }

 

  // Debug
  Serial.print("presence: ");
  Serial.println(digitalRead(presence));
  Serial.print("hum: ");
  Serial.println(humidite);
  Serial.print("temp: ");
  Serial.println(temperature);
}


