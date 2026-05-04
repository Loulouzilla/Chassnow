#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  // Fréquence à 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  
  Serial.begin(9600);
}

void loop() {
  // --- ROUGE ---
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  int rawR = pulseIn(sensorOut, LOW);
  // Utilise 7 comme valeur mini (Blanc) et environ 100 pour le Noir
  int R = map(rawR, 7, 100, 255, 0); 
  R = constrain(R, 0, 255);

  // --- VERT ---
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  int rawV = pulseIn(sensorOut, LOW);
  int V = map(rawV, 8, 110, 255, 0); 
  V = constrain(V, 0, 255);

  // --- BLEU ---
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  int rawB = pulseIn(sensorOut, LOW);
  int B = map(rawB, 6, 90, 255, 0); 
  B = constrain(B, 0, 255);

  // Affichage
  Serial.print("R:"); Serial.print(R);
  Serial.print(" V:"); Serial.print(V);
  Serial.print(" B:"); Serial.println(B);

  delay(500);
}