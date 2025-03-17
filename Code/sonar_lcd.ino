#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// Initialisation de l'écran LCD (adresse I2C 0x27, écran 16x2)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Définition des broches utilisées pour le capteur ultrasonique
const int trigPin = 11; // Broche Trigger (émission)
const int echoPin = 12; // Broche Echo (réception)

// Variables utilisées pour le calcul de la distance
long duree;     // Durée du signal d'écho
int distance;   // Distance calculée en cm

void setup() { 
    // Configuration des broches du capteur
    pinMode(trigPin, OUTPUT); // Trigger en sortie
    pinMode(echoPin, INPUT);  // Echo en entrée
    
    // Initialisation de l'écran LCD
    lcd.init();
    lcd.backlight(); // Activation du rétroéclairage
} 

void loop() { 
    // Émission d'un signal de 10 microsecondes
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(5); 
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10); 
    digitalWrite(trigPin, LOW); 

    // Mesure de la durée du signal d'écho
    duree = pulseIn(echoPin, HIGH); 

    // Calcul de la distance en cm (vitesse du son = 0.034 cm/µs)
    distance = duree * 0.034 / 2; 

    // Affichage sur l'écran LCD
    lcd.clear(); // Effacer l'écran avant d'afficher une nouvelle valeur
    lcd.setCursor(0, 0); // Placer le curseur en haut à gauche
    lcd.print("Distance:"); // Afficher "Distance:"
    lcd.setCursor(0, 1); // Placer le curseur en bas à gauche
    lcd.print(distance); // Afficher la valeur de la distance
    lcd.print(" cm"); // Ajouter "cm" après la valeur

    delay(100); // Mise à jour rapide
}