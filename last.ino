
#include <SPI.h>
#include <MFRC522.h>
//#include <Servo.h>
 
#define SS_PIN 10
#define RST_PIN 9
//#define LED_G 5 //définir la LED verte
//#define LED_R 4 //définir la LED rouge
//#define BUZZER 2 //buzzer pin
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Créer MFRC522 en instance.
//Servo myServo; //definir le nom du servo 
 
void setup() 
{
  Serial.begin(9600);   // Initialiser la communication en série
  SPI.begin();      // Initialiser le bus  SPI 
  mfrc522.PCD_Init();   // Initialiser MFRC522
//  myServo.attach(3); //servo pin
  //myServo.write(0); //servo start position
//  pinMode(LED_G, OUTPUT);
  //pinMode(LED_R, OUTPUT);
  //pinMode(BUZZER, OUTPUT);
  //noTone(BUZZER);
  Serial.println("Mettez votre carte au lecteur...");
  Serial.println();

}
void loop() 
{
  // chercher de nouvelles cartes
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Selectionner une des cartes
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //montrer UID sur le moniteur en série
  //Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     
    // Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    // Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
   content.toUpperCase();
   //envoi de IDTAG
  Serial.println(content);
 
  delay(2000);
  /*Serial.print("Message : ");
  content.toUpperCase();
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));*/
  
  
  /*if (content.substring(1) == "10 4D 7B 7A") // UID auquel on veut donner l'accès
  {
    Serial.println("Acces autorise");
    Serial.println();
    delay(500);
    digitalWrite(LED_G, HIGH);
    //tone(BUZZER, 500);
    //delay(300);
   // noTone(BUZZER);
    myServo.write(180);
    delay(5000);
    myServo.write(0);
    digitalWrite(LED_G, LOW);
  }
 
 else   {
    Serial.println(" Acces refuse");
    digitalWrite(LED_R, HIGH);
    //tone(BUZZER, 300);
    delay(1000);
    digitalWrite(LED_R, LOW);
    //noTone(BUZZER);
  }*/
}

