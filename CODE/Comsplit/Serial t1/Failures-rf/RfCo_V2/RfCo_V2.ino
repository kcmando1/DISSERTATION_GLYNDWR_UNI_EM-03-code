
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>

char msg[16];

RF24 radio(9,10);
byte addresses[][6] = {"1Node","2Node"};    

bool sw=0;//If is node connected to computer 1 marks priority. 
bool radioNumber = 0;
char dare=0,s=0;
void setup(void){
  Serial.begin(115200);
  radio.begin();
               
  if(radioNumber){
    radio.openWritingPipe(addresses[1]);        // Both radios listen on the same pipes by default, but opposite addresses
    radio.openReadingPipe(1,addresses[0]);      // Open a reading pipe on address 0, pipe 1
  }else{
    radio.openWritingPipe(addresses[0]);
    radio.openReadingPipe(1,addresses[1]);
  }
  radio.startListening();                       // Start listening  
     
  
}
 
void loop(void){
  
  //Serial.print("sender=");
  //Serial.println(sw);
    radio.stopListening();
    Serial.println("w-mode");
    while(!Serial.available()){}
    do{
    if(Serial.available()){
      radio.write(s=Serial.read(), sizeof(char));
      Serial.print("payload=");
      Serial.println(s);        
    }
    }while(Serial.available());
    Serial.println("w-end");
  
}
