#include "CTBot.h"
CTBot myBot;

String ssid = "IndiHome";     // Sesuikan dengan nama wifi anda
String pass = "adminadmin"; // sesuaikan password wifi
String token = "1099878331:AAEuK1bcpwelALZfe9bWQs9syG1Cg-YDwpM"; // token bot telegram yang telah dibuat

String data;
char c;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting TelegramBot...");

  myBot.wifiConnect(ssid, pass);

  myBot.setTelegramToken(token);

  // check if all things are ok
  if (myBot.testConnection())
    Serial.println("\ntestConnection OK");
  else
    Serial.println("\ntestConnection NOK");

}

void loop() {
  TBMessage msg;

  if (myBot.getNewMessage(msg)) {

    if (msg.text.equalsIgnoreCase("TEMPERATURE")) {
      Serial.print("TEMPERATURE");
    }
    else if (msg.text.equalsIgnoreCase("TOMAT")) {        
      myBot.sendMessage(msg.sender.id, "Tumbuhan telah diubah ke TOMAT"); 
      Serial.print("TOMAT");
    }
    else if (msg.text.equalsIgnoreCase("CABAI")) {        
      myBot.sendMessage(msg.sender.id, "Tumbuhan telah diubah ke CABAI"); 
      Serial.print("CABAI");
    }
    else if (msg.text.equalsIgnoreCase("BAYAM")) {        
      myBot.sendMessage(msg.sender.id, "Tumbuhan telah diubah ke BAYAM"); 
      Serial.print("BAYAM");
    }
    else {                                                    
      // membalas pesan selain kode diatas
      String reply;
      reply = (String)"Welcome " + msg.sender.username + (String)". Command yang tersedia: TEMPERATURE, TOMAT, CABAI dan BAYAM.";
      myBot.sendMessage(msg.sender.id, reply);         
    }
  }
  
  while(Serial.available()>0){
    delay(10);
    c = Serial.read();
    data += c;
  }
  if (data.length()>0) {
    myBot.sendMessage(msg.sender.id, "Kelembapan Tanah : " + data + (String)" %");
    delay(10);
    data = "";
  }

  delay(500);
}
