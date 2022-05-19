
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define width 128  // taille de la largeur en pixel de l'ecran
#define height 64   // taille de la hauteur en pixel de l'ecran

Adafruit_SSD1306 oled (width, height,&Wire, -1);

//#include <SoftwareSerial.h>
//#include "SerialTransfer.h"

//int Potentio1 = A2; // Pin A2 Arduino vers broche Y du Joystick
//int Potentio = A3; // Pin A3 Arduino vers broche X du Joystick

//int ValeurPot=0;// Valeur du Joystick X
//int ValeurPot1=0;// Vaeur du Joystick Y
const int button = 9;
int buttonState = 0;
const int led = 4;
bool valbp = 0;




void setup() {
  Serial.begin (9600);
  
  pinMode(button,INPUT_PULLUP);
  pinMode(led,OUTPUT);
  
// initialise l'affichage OLED avec l'adresse 0x3C pour 128x64 
  if (! oled.begin (SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println (F( "Echec de l'allocation SSD1306")); 
    while ( true ); }
    delay (2000);
    oled.clearDisplay(); // clear display

    oled.setTextSize(1);          // text size
    oled.setTextColor(WHITE);     // text color
    oled.setCursor(0, 10);        // position to display
    oled.println("Bienvenue surle Robot!"); // text to display
    oled.setCursor(0, 30);        // position to display
    oled.println("Presentez une carte!"); // text to display
    oled.display();               // show on OLED  
    delay (5000);
} 

void loop() {
 buttonState = digitalRead(button);
  Serial.println(buttonState);

  if(buttonState == LOW)  {       // If button is not pressing
    oled.clearDisplay();
    oled.setCursor(0,20);
    oled.println("MODE MANUEL");
    digitalWrite(led, LOW); // turn oFF LED
    oled.display();
    }
  else {                          // otherwise, button is pressing
    digitalWrite(led, HIGH);  // turn on LED
    oled.clearDisplay();
    oled.setCursor(0,20);
    oled.println("MODE AUTOMATIQUE");
    oled.display();
  
 } 
}
