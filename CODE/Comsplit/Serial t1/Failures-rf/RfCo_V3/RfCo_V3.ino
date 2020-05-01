
/*
* Getting Started example sketch for nRF24L01+ radios
* This is an example of how to send data from one node to another using data structures
* Updated: Dec 2014 by TMRh20
*/

#include <SPI.h>
#include "RF24.h"

byte addresses[][6] = {"1Node","2Node"};


/****************** User Config ***************************/
/***      Set this radio as radio number 0 or 1         ***/
bool radioNumber = 0;
char s=0;
int c=0;
char aux;

/* Hardware configuration: Set up nRF24L01 radio on SPI bus plus pins 7 & 8 */
RF24 radio(9,10);
/**********************************************************/


// Used to control whether this node is sending or receiving
bool role = 0;

/**
* Create a data structure for transmitting and receiving data
* This allows many variables to be easily sent and received in a single transmission
* See http://www.cplusplus.com/doc/tutorial/structures/
*/
struct dataStruct{
  char payload[50];
  int a=1;
}myData;

void setup() {

  Serial.begin(115200);

  radio.begin();

  // Set the PA Level low to prevent power supply related issues since this is a
 // getting_started sketch, and the likelihood of close proximity of the devices. RF24_PA_MAX is default.
  radio.setPALevel(RF24_PA_LOW);
  
  // Open a writing and reading pipe on each radio, with opposite addresses
  if(radioNumber){
    radio.openWritingPipe(addresses[1]);
    radio.openReadingPipe(1,addresses[0]);
  }else{
    radio.openWritingPipe(addresses[0]);
    radio.openReadingPipe(1,addresses[1]);
  }
  
  
  // Start the radio listening for data
  radio.startListening();
}




void loop() {
  
  
/****************** Ping Out Role ***************************/  
    radio.stopListening();                                    // First, stop listening so we can talk. 
    Serial.println("TX_mode");
    Serial.flush();
    while(!Serial.available()){}
    c=0;
    while(Serial.available()){
      aux=Serial.read();
      myData.payload[c]=aux;
      c++;
      Serial.println(c);
      delay(0.9);
    };
    Serial.println(myData.payload);
    if (!radio.write(&myData, sizeof(myData) )){
      Serial.println(F("failed"));
    }
    
    Serial.println("RX_mode");    
    radio.startListening();                                    // Now, continue listening
    
                                  // Set up a variable to indicate if a response was received or not
    
    while ( ! radio.available() ){}                             // While nothing is received
          radio.read(&myData,sizeof(myData));
          Serial.println(myData.payload);
   
} // Loop
