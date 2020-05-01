

#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>

char msg[16]="Prometec.net.\n" ;                             // Array a transmitir
RF24 radio(9,53);                        // Creamos un objeto radio del tipo RF2$
const uint64_t pipe = 0xE8E8F0F0E1LL;    // Usamos este canal
 
void setup(void){
  Serial.begin(115200);
  radio.begin();
  radio.openWritingPipe(pipe);}          // Abrir para escribir
 
void loop(void)
{
    radio.write(msg, 16);
    Serial.println("ack");
}
