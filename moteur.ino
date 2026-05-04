// ====== MOTEUR GAUCHE ======
const int pinVitesseG = 9;      // VR (PWM)
const int pinDirectionG = 8;    // Z/F
const int pinFreinG = 7;        // EL

// ====== MOTEUR DROIT ======
const int pinVitesseD = 10;     // VR (PWM)
const int pinDirectionD = 12;   // Z/F
const int pinFreinD = 11;       // EL

// ====== PARAMETRES ======
int vitesse = 150;  // 0 à 255 (150 ≈ 60%)

void setup() {
  pinMode(pinVitesseG, OUTPUT);
  pinMode(pinDirectionG, OUTPUT);
  pinMode(pinFreinG, OUTPUT);

  pinMode(pinVitesseD, OUTPUT);
  pinMode(pinDirectionD, OUTPUT);
  pinMode(pinFreinD, OUTPUT);

  Serial.begin(9600);

  // Activer moteurs (pas de frein)
  digitalWrite(pinFreinG, HIGH);
  digitalWrite(pinFreinD, HIGH);

  stopMoteurs();

  Serial.println("Systeme pret. Demarrage dans 2 secondes...");
  delay(2000);
}

void loop() {

  Serial.println("AVANCER");
  avancer(vitesse);
  delay(3000);

  Serial.println("STOP");
  stopMoteurs();
  delay(1000);

  Serial.println("TOURNER A GAUCHE");
  tournerGauche(vitesse);
  delay(2000);

  Serial.println("STOP");
  stopMoteurs();
  delay(1000);

  Serial.println("TOURNER A DROITE");
  tournerDroite(vitesse);
  delay(2000);

  Serial.println("STOP");
  stopMoteurs();
  delay(1000);

  Serial.println("RECULER");
  reculer(vitesse);
  delay(3000);

  Serial.println("STOP");
  stopMoteurs();
  delay(2000);
}


// =================== FONCTIONS ===================

// Stop complet
void stopMoteurs() {
  analogWrite(pinVitesseG, 0);
  analogWrite(pinVitesseD, 0);
}

// Avancer : les 2 moteurs dans le même sens
// Avancer
void avancer(int vit) {
  digitalWrite(pinDirectionG, LOW);
  digitalWrite(pinDirectionD, HIGH);   // INVERSE

  analogWrite(pinVitesseG, vit);
  analogWrite(pinVitesseD, vit);
}

// Reculer
void reculer(int vit) {
  digitalWrite(pinDirectionG, HIGH);
  digitalWrite(pinDirectionD, LOW);    // INVERSE

  analogWrite(pinVitesseG, vit);
  analogWrite(pinVitesseD, vit);
}

// Tourner à gauche
void tournerGauche(int vit) {
  digitalWrite(pinDirectionG, LOW);
  digitalWrite(pinDirectionD, HIGH);

  analogWrite(pinVitesseG, vit / 3);
  analogWrite(pinVitesseD, vit);
}

// Tourner à droite
void tournerDroite(int vit) {
  digitalWrite(pinDirectionG, LOW);
  digitalWrite(pinDirectionD, HIGH);

  analogWrite(pinVitesseG, vit);
  analogWrite(pinVitesseD, vit / 3);
}
