#include LiquidCrystal_I2C.h;
#include  Wire.h;

LiquidCrystal_I2C lcd(0x27,  16, 2);
// Définition des numéros de port 
const int trigPin = 11; // Trigger (emission) 
const int echoPin = 12; // Echo (réception) 
// Variables utiles 
long duree; // durée de l'echo 
int distance; // distance 

void setup() { 
   pinMode(trigPin, OUTPUT); // Configuration du port du Trigger comme une SORTIE 
   pinMode(echoPin, INPUT); // Configuration du port de l'Echo comme une ENTREE 
   //initialize lcd screen
    lcd.init();
    // turn on the backlight
    lcd.backlight();
   Serial.begin(9600); // Démarrage de la communication série 
} 

void loop() { 
   // Émission d'un signal de durée 10 microsecondes 
   digitalWrite(trigPin, LOW); 
   delayMicroseconds(5); 
   digitalWrite(trigPin, HIGH); 
   delayMicroseconds(10); 
   digitalWrite(trigPin, LOW); 

   // Écoute de l'écho 
   duree = pulseIn(echoPin, HIGH); 

   // Calcul de la distance 
   distance = duree*0.034/2; 

   // Affichage de la distance dans le Moniteur Série 
   Serial.print("Distance : "); 
   Serial.print(distance); 
   Serial.println("cm");
    delay(1000)
// tell the screen to write on the top row
  lcd.setCursor(0,0);
  // tell the screen to write “hello, from” on the top  row
  lcd.print(“Distance”);
  // tell the screen to write on the bottom  row
  lcd.setCursor(0,1);
  // tell the screen to write “Arduino_uno_guy”  on the bottom row
  // you can change whats in the quotes to be what you want  it to be!
  lcd.print(“Arduino_uno_guy”); 
}
