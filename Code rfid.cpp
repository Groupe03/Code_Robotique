#include <Arduino.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h> // SPI
#include <MFRC522.h> // RFID
#define SS_PIN 53
#define RST_PIN 49

MFRC522 mfrc522(SS_PIN, RST_PIN) ; // intance of the class
void setup() {
  Serial.begin(9600);
  SPI.begin(); // Init SPI bus
  mfrc522.PCD_Init() ; // Init MFRC522
  Serial.println("Scannez votre Badge") ;
}
void loop (){
if (mfrc522.PICC_IsNewCardPresent())
    {
      if (mfrc522.PICC_ReadCardSerial())      
      {
          Serial.print("Code Badge:") ;
          for (byte i = 0; i < mfrc522.uid.size; i++){
            Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ") ;
            Serial.print(mfrc522.uid.uidByte[i], HEX) ;
          }

          Serial.println() ;
          mfrc522.PICC_HaltA() ;
      }
    }         
}
