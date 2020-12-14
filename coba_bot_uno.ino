#include <SoftwareSerial.h>
SoftwareSerial mySerial(2,3);
String data;
char c;
const int relay = 6;

int lm35 = A0;
int val;
float mv;
float temp;
const int ledGreen = 7;    //inisialisasi pin led hijau
const int ledYellow = 8;   //inisialisasi pin led kuning
const int ledRed = 9;      //inisialisasi pin hijau
String tanaman = "TOMAT";

void setup() {
  Serial.begin(115200);
  mySerial.begin(115200);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
  pinMode(lm35, INPUT);   //menetapkan pin A0 sebagai input
  pinMode(ledGreen, OUTPUT);    //menetapkan pin 7 sebagai output
  pinMode(ledYellow, OUTPUT);   //menetapkan pin 8 sebagai output
  pinMode(ledRed, OUTPUT);      //menetapkan pin 9 sebagai output
  delay(10);
}

void loop() {
  while(mySerial.available()>0){
    delay(10);
    c = mySerial.read();
    data += c;
  }
   val = analogRead(lm35);
      mv = ((val/1023.00)*100);
      temp = 100-mv;

if (tanaman == "CABAI"){
      if (temp > 60) {
        Serial.print (". Kelembapan tanah CABAI : "); 
        Serial.print (temp);
        Serial.println ("%");    
        Serial.println(". Media Terlalu Basah"); 
        digitalWrite (ledGreen, HIGH);
        digitalWrite (ledYellow, LOW);
        digitalWrite (ledRed, LOW);
        digitalWrite (relay, HIGH);
        }
      
       //tetapi, jika nilai A0 kurang dari 900, print kata serta nyalakan led kuning dan relay kemudian matikan led hijau dan juga merah
       else if (temp > 40) {
        Serial.print (". Kelembapan tanah CABAI : ");
        Serial.print (temp);
        Serial.println ("%");
        Serial.println(". Kelembaban Tanah Ideal"); 
        digitalWrite (ledGreen, LOW);
        digitalWrite (ledYellow, HIGH);
        digitalWrite (ledRed, LOW);
        digitalWrite (relay, HIGH);
        }
      
       //selain dari itu, hanya nyalakan led merah dan juga relay
       else { 
        Serial.print (". Kelembapan tanah CABAI : ");
        Serial.print (temp);
        Serial.println ("%");
        Serial.println (". Perlu Tambahan Air"); 
        digitalWrite (ledGreen, LOW);
        digitalWrite (ledYellow, LOW);
        digitalWrite (ledRed, HIGH);
        digitalWrite (relay, LOW);
        }
      
       delay (1500);
       } 

else if (tanaman == "BAYAM"){
      if (temp > 50) {
        Serial.print (". Kelembapan tanah BAYAM : "); 
        Serial.print (temp);
        Serial.println ("%");    
        Serial.println(". Media Terlalu Basah"); 
        digitalWrite (ledGreen, HIGH);
        digitalWrite (ledYellow, LOW);
        digitalWrite (ledRed, LOW);
        digitalWrite (relay, HIGH);
        }
      
       //tetapi, jika nilai A0 kurang dari 900, print kata serta nyalakan led kuning dan relay kemudian matikan led hijau dan juga merah
       else if (temp > 30) {
        Serial.print (". Kelembapan tanah BAYAM : ");
        Serial.print (temp);
        Serial.println ("%");
        Serial.println(". Kelembaban Tanah Ideal"); 
        digitalWrite (ledGreen, LOW);
        digitalWrite (ledYellow, HIGH);
        digitalWrite (ledRed, LOW);
        digitalWrite (relay, HIGH);
        }
      
       //selain dari itu, hanya nyalakan led merah dan juga relay
       else { 
        Serial.print (". Kelembapan tanah BAYAM : ");
        Serial.print (temp);
        Serial.println ("%");
        Serial.println (". Perlu Tambahan Air"); 
        digitalWrite (ledGreen, LOW);
        digitalWrite (ledYellow, LOW);
        digitalWrite (ledRed, HIGH);
        digitalWrite (relay, LOW);
        }
      
       delay (1500);
       }

else {
      if (temp > 40) {
        Serial.print (". Kelembapan tanah TOMAT : "); 
        Serial.print (temp);
        Serial.println ("%");    
        Serial.println(". Media Terlalu Basah"); 
        digitalWrite (ledGreen, HIGH);
        digitalWrite (ledYellow, LOW);
        digitalWrite (ledRed, LOW);
        digitalWrite (relay, HIGH);
        }
      
       //tetapi, jika nilai A0 kurang dari 900, print kata serta nyalakan led kuning dan relay kemudian matikan led hijau dan juga merah
       else if (temp > 20) {
        Serial.print (". Kelembapan tanah TOMAT : ");
        Serial.print (temp);
        Serial.println ("%");
        Serial.println(". Kelembaban Tanah Ideal"); 
        digitalWrite (ledGreen, LOW);
        digitalWrite (ledYellow, HIGH);
        digitalWrite (ledRed, LOW);
        digitalWrite (relay, HIGH);
        }
      
       //selain dari itu, hanya nyalakan led merah dan juga relay
       else { 
        Serial.print (". Kelembapan tanah TOMAT : ");
        Serial.print (temp);
        Serial.println ("%");
        Serial.println (". Perlu Tambahan Air"); 
        digitalWrite (ledGreen, LOW);
        digitalWrite (ledYellow, LOW);
        digitalWrite (ledRed, HIGH);
        digitalWrite (relay, LOW);
        }
      
       delay (1500);
       }
       
  if (data.length()>0) {
    Serial.println(data);
    if (data == "TEMPERATURE") {
       val = analogRead(lm35);
      mv = ((val/1023.00)*100);
      temp = 100-mv;
      mySerial.print(temp);
      Serial.println(temp);
    }
    else if (data == "TOMAT") {
       tanaman = "TOMAT";
    }
    else if (data == "CABAI") {
      tanaman = "CABAI";
    }
    else if (data == "BAYAM") {
       tanaman = "BAYAM";
    }    
    data = "";
  }
}
