typedef struct { //reciever structure with the names of the variables of the engine ECU. 
  int seconds;
  int pulseWidth1;
  int pulseWidth2;
  int rpms;
  int advance;
  int squirt;
  int engine;
  int afrtgt1;
  int afrtgt2;
  int wbo2_en1;
  int wbo2_en2;
  int barometer;
  int mapp;
  int matt;
  int coolant;
  int tpss;
  int batteryVoltage;
  int afr1;
  int afr2;
  int knock;
  int egocor1;
  int egocor2;
  int aircor;
  int warmcor;
  int accelEnrich;
  int tpsfuelcut;
  int baroCorrection;
  int gammaEnrich;
  int ve1;
  int ve2;
  int iacstep;
  int cold_adv_deg;
  int TPSdot;
  int MAPdot;
  int dwell;
  int MAFFF;
  int fuelload;
  int fuelcor;
  int portStatus;
  int knockRetard;
  int EAEfcor1;
  int egoV1;
  int egoV2;
  int amcUpdates;
  int kpaix;
  int EAEfcor2;
  int spare1;
  int spare2;
  int trig_fix;
  int spare4;
  int spare5;
  int spare6;
  int spare7;
  int spare8;
  int spare9;
  int spare10;
  int tachCount;
  int ospare;
  int cksum;
  int deltaT;
} tEcu;
tEcu dataReciever;
tEcu dataSender;
typedef struct{
  int val[60];
  int tam[60];
}data;
data a;


void setup() {
    Serial.begin(115200);
    Serial1.begin(115200);
  // put your setup code here, to run once:
  a.val[0]=dataSender.seconds=65536;
  a.val[1]=dataSender.pulseWidth1=65536;
  a.val[2]=dataSender.pulseWidth2=65536;
  a.val[3]=dataSender.rpms=65536;
  a.val[4]=dataSender.advance=65536;
  a.val[5]=dataSender.squirt=256;
  a.val[6]=dataSender.engine=256;
  a.val[7]=dataSender.afrtgt1=256;
  a.val[8]=dataSender.afrtgt2=256;
  a.val[9]=dataSender.wbo2_en1=256;
  a.val[1]=dataSender.wbo2_en2=256;
  a.val[11]=dataSender.barometer=65536;
  a.val[12]=dataSender.mapp=65536;
  a.val[13]=dataSender.matt=65536;
  a.val[14]=dataSender.coolant=65536;
  a.val[15]=dataSender.tpss=65536;
  a.val[16]=dataSender.batteryVoltage=65536;
  a.val[17]=dataSender.afr1=65536;
  a.val[18]=dataSender.afr2=65536;
  a.val[19]=dataSender.knock=65536;
  a.val[20]=dataSender.egocor1=65536;
  a.val[21]=dataSender.egocor2=65536;
  a.val[22]=dataSender.aircor=65536;
  a.val[23]=dataSender.warmcor=65536;
  a.val[24]=dataSender.accelEnrich=65536;
  a.val[25]=dataSender.tpsfuelcut=65536;
  a.val[26]=dataSender.baroCorrection=65536;
  a.val[27]=dataSender.gammaEnrich=65536;
  a.val[28]=dataSender.ve1=65536;
  a.val[29]=dataSender.ve2=65536;
  a.val[30]=dataSender.iacstep=65536;
  a.val[31]=dataSender.cold_adv_deg=65536;
  a.val[32]=dataSender.TPSdot=65536;
  a.val[33]=dataSender.MAPdot=65536;
  a.val[34]=dataSender.dwell=65536;
  a.val[35]=dataSender.MAFFF=65536;
  a.val[36]=dataSender.fuelload=256;
  a.val[37]=dataSender.fuelcor=65536;
  a.val[38]=dataSender.portStatus=256;
  a.val[39]=dataSender.knockRetard=65536;
  a.val[40]=dataSender.EAEfcor1=65536;
  a.val[41]=dataSender.egoV1=65536;
  a.val[42]=dataSender.egoV2=65536;
  a.val[43]=dataSender.amcUpdates=65536;
  a.val[44]=dataSender.kpaix=65536;
  a.val[45]=dataSender.EAEfcor2=65536;
  a.val[46]=dataSender.spare1=65536;
  a.val[47]=dataSender.spare2=65536;
  a.val[48]=dataSender.trig_fix=65536;
  a.val[49]=dataSender.spare4=65536;
  a.val[50]=dataSender.spare5=65536;
  a.val[51]=dataSender.spare6=65536;
  a.val[52]=dataSender.spare7=65536;
  a.val[53]=dataSender.spare8=65536;
  a.val[54]=dataSender.spare9=65536;
  a.val[55]=dataSender.spare10=65536;
  a.val[56]=dataSender.tachCount=65536;
  a.val[57]=dataSender.ospare=256;
  a.val[58]=dataSender.cksum=65536;
  a.val[59]=dataSender.deltaT=4294967296;
  //-------------------------------------//
  a.tam[0]=2;//byte size of seconds
  a.tam[1]=2;//byte size of pulseWidth1
  a.tam[2]=2;//byte size of pulseWidth2
  a.tam[3]=2;//byte size of rpms
  a.tam[4]=2;//byte size of advance
  a.tam[5]=1;//byte size of squirt
  a.tam[6]=1;//byte size of engine
  a.tam[7]=1;//byte size of afrtgt1
  a.tam[8]=1;//byte size of afrtgt2
  a.tam[9]=1;//byte size of wbo2_en1
  a.tam[1]=1;//byte size of wbo2_en2
  a.tam[11]=2;//byte size of barometer
  a.tam[12]=2;//byte size of mapp
  a.tam[13]=2;//byte size of matt
  a.tam[14]=2;//byte size of coolant
  a.tam[15]=2;//byte size of tpss
  a.tam[16]=2;//byte size of batteryVoltage
  a.tam[17]=2;//byte size of afr1
  a.tam[18]=2;//byte size of afr2
  a.tam[19]=2;//byte size of knock
  a.tam[20]=2;//byte size of egocor1
  a.tam[21]=2;//byte size of egocor2
  a.tam[22]=2;//byte size of aircor
  a.tam[23]=2;//byte size of warmcor
  a.tam[24]=2;//byte size of accelEnrich
  a.tam[25]=2;//byte size of tpsfuelcut
  a.tam[26]=2;//byte size of baroCorrection
  a.tam[27]=2;//byte size of gammaEnrich
  a.tam[28]=2;//byte size of ve1
  a.tam[29]=2;//byte size of ve2
  a.tam[30]=2;//byte size of iacstep
  a.tam[31]=2;//byte size of cold_adv_deg
  a.tam[32]=2;//byte size of TPSdot
  a.tam[33]=2;//byte size of MAPdot
  a.tam[34]=2;//byte size of dwell
  a.tam[35]=2;//byte size of MAFFF
  a.tam[36]=1;//byte size of fuelload
  a.tam[37]=2;//byte size of fuelcor
  a.tam[38]=1;//byte size of portStatus
  a.tam[39]=2;//byte size of knockRetard
  a.tam[40]=2;//byte size of EAEfcor1
  a.tam[41]=2;//byte size of egoV1
  a.tam[42]=2;//byte size of egoV2
  a.tam[43]=2;//byte size of amcUpdates
  a.tam[44]=2;//byte size of kpaix
  a.tam[45]=2;//byte size of EAEfcor2
  a.tam[46]=2;//byte size of spare1
  a.tam[47]=2;//byte size of spare2
  a.tam[48]=2;//byte size of trig_fix
  a.tam[49]=2;//byte size of spare4
  a.tam[50]=2;//byte size of spare5
  a.tam[51]=2;//byte size of spare6
  a.tam[52]=2;//byte size of spare7
  a.tam[53]=2;//byte size of spare8
  a.tam[54]=2;//byte size of spare9
  a.tam[55]=2;//byte size of spare10
  a.tam[56]=2;//byte size of tachCount
  a.tam[57]=1;//byte size of ospare
  a.tam[58]=2;//byte size of cksum
  a.tam[59]=4;//byte size of deltaT
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(Serial.read()=='a'){
    Serial1.write('a');
    aReciever(dataSender,dataReciever);
  }
  
}
void aReciever(tEcu dataSender,tEcu dataReciever){
  byte respuesta[50];
  byte inbyte;
  int m=0;
  Serial1.flush();
   if (Serial1.available()){
    //Serial1.println("..  CCCCC.");
   while (Serial1.available()){
    inbyte = Serial1.read();
    //resp[m]=(char) inbyte; // lligat a la funció  datalog 2 conerteix (malament) de bit a char
    respuesta[m]=inbyte;
    m++;
    
    delay(0.9);
    }
  }
     
  dataReciever.seconds=llegirposicio(2,0,1,respuesta);
  dataReciever.pulseWidth1=llegirposicio(2,2,1000,respuesta);
  dataReciever.pulseWidth2=llegirposicio(2,4,1000,respuesta);
  dataReciever.rpms=llegirposicio(2,6,1,respuesta);
  dataReciever.advance=llegirposicio(2,8,10,respuesta);
  dataReciever.squirt=llegirposicio(1,10,1,respuesta);
  dataReciever.engine=llegirposicio(1,11,1,respuesta);
  dataReciever.afrtgt1=llegirposicio(1,12,10,respuesta);
  dataReciever.afrtgt2=llegirposicio(1,13,10,respuesta);
  dataReciever.wbo2_en1=llegirposicio(1,14,1,respuesta);
  dataReciever.wbo2_en2=llegirposicio(1,15,1,respuesta);
  dataReciever.barometer=llegirposicio(2,16,10,respuesta);
  dataReciever.mapp=llegirposicio(2,18,10,respuesta);
  dataReciever.matt=llegirposicio(2,20,10,respuesta);
  dataReciever.coolant=llegirposicio(2,22,10,respuesta);
  dataReciever.tpss=llegirposicio(2,24,10,respuesta);
  dataReciever.batteryVoltage=llegirposicio(2,26,10,respuesta);
  dataReciever.afr1=llegirposicio(2,28,10,respuesta);
  dataReciever.afr2=llegirposicio(2,30,10,respuesta);
  dataReciever.knock=llegirposicio(2,32,10,respuesta);
  dataReciever.egocor1=llegirposicio(2,34,10,respuesta);
  dataReciever.egocor2=llegirposicio(2,36,10,respuesta);
  dataReciever.aircor=llegirposicio(2,38,10,respuesta);
  dataReciever.warmcor=llegirposicio(2,40,10,respuesta);
  dataReciever.accelEnrich=llegirposicio(2,42,10,respuesta);
  dataReciever.tpsfuelcut=llegirposicio(2,44,10,respuesta);
  dataReciever.baroCorrection=llegirposicio(2,46,10,respuesta);
  dataReciever.gammaEnrich=llegirposicio(2,48,10,respuesta);
  dataReciever.ve1=llegirposicio(2,50,10,respuesta);
  dataReciever.ve2=llegirposicio(2,52,10,respuesta);
  dataReciever.iacstep=llegirposicio(2,54,1,respuesta);
  dataReciever.cold_adv_deg=llegirposicio(2,56,10,respuesta);
  dataReciever.TPSdot=llegirposicio(2,58,10,respuesta);
  dataReciever.MAPdot=llegirposicio(2,60,10,respuesta);
  dataReciever.dwell=llegirposicio(2,62,10,respuesta);
  dataReciever.MAFFF=llegirposicio(2,64,100,respuesta);
  dataReciever.fuelload=llegirposicio(1,66,10,respuesta);
  dataReciever.fuelcor=llegirposicio(2,68,1,respuesta);
  dataReciever.portStatus=llegirposicio(1,70,1,respuesta);
  dataReciever.knockRetard=llegirposicio(2,71,10,respuesta);
  dataReciever.EAEfcor1=llegirposicio(2,72,1,respuesta);
  dataReciever.egoV1=llegirposicio(2,74,100,respuesta);
  dataReciever.egoV2=llegirposicio(2,76,100,respuesta);
  dataReciever.amcUpdates=llegirposicio(2,78,1,respuesta);
  dataReciever.kpaix=llegirposicio(2,80,1,respuesta);
  dataReciever.EAEfcor2=llegirposicio(2,82,1,respuesta);
  dataReciever.spare1=llegirposicio(2,84,1,respuesta);
  dataReciever.spare2=llegirposicio(2,86,1,respuesta);
  dataReciever.trig_fix=llegirposicio(2,88,1,respuesta);
  dataReciever.spare4=llegirposicio(2,90,1,respuesta);
  dataReciever.spare5=llegirposicio(2,92,1,respuesta);
  dataReciever.spare6=llegirposicio(2,94,1,respuesta);
  dataReciever.spare7=llegirposicio(2,96,1,respuesta);
  dataReciever.spare8=llegirposicio(2,98,1,respuesta);
  dataReciever.spare9=llegirposicio(2,100,1,respuesta);
  dataReciever.spare10=llegirposicio(2,102,1,respuesta);
  dataReciever.tachCount=llegirposicio(2,104,1,respuesta);
  dataReciever.ospare=llegirposicio(1,106,1,respuesta);
  dataReciever.cksum=llegirposicio(2,107,1,respuesta);
  dataReciever.deltaT=llegirposicio(4,108,1,respuesta);

  int ans=0,ro=0;
  if(dataReciever.seconds!=dataSender.seconds){ro++;Serial.print("seconds->");Serial.println(dataReciever.seconds);}
  if(dataReciever.pulseWidth1!=dataSender.pulseWidth1){ro++;Serial.print("pulseWidth1->");Serial.println(dataReciever.pulseWidth1);}
  if(dataReciever.pulseWidth2!=dataSender.pulseWidth2){ro++;Serial.print("pulseWidth2->");Serial.println(dataReciever.pulseWidth2);}
  if(dataReciever.rpms!=dataSender.rpms){ro++;Serial.print("rpms->");Serial.println(dataReciever.rpms);}
  if(dataReciever.advance!=dataSender.advance){ro++;Serial.print("advance->");Serial.println(dataReciever.advance);}
  if(dataReciever.squirt!=dataSender.squirt){ro++;Serial.print("squirt->");Serial.println(dataReciever.squirt);}
  if(dataReciever.engine!=dataSender.engine){ro++;Serial.print("engine->");Serial.println(dataReciever.engine);}
  if(dataReciever.afrtgt1!=dataSender.afrtgt1){ro++;Serial.print("afrtgt1->");Serial.println(dataReciever.afrtgt1);}
  if(dataReciever.afrtgt2!=dataSender.afrtgt2){ro++;Serial.print("afrtgt2->");Serial.println(dataReciever.afrtgt2);}
  if(dataReciever.wbo2_en1!=dataSender.wbo2_en1){ro++;Serial.print("wbo2_en1->");Serial.println(dataReciever.wbo2_en1);}
  if(dataReciever.wbo2_en2!=dataSender.wbo2_en2){ro++;Serial.print("wbo2_en2->");Serial.println(dataReciever.wbo2_en2);}
  if(dataReciever.barometer!=dataSender.barometer){ro++;Serial.print("barometer->");Serial.println(dataReciever.barometer);}
  if(dataReciever.mapp!=dataSender.mapp){ro++;Serial.print("mapp->");Serial.println(dataReciever.mapp);}
  if(dataReciever.matt!=dataSender.matt){ro++;Serial.print("matt->");Serial.println(dataReciever.matt);}
  if(dataReciever.coolant!=dataSender.coolant){ro++;Serial.print("coolant->");Serial.println(dataReciever.coolant);}
  if(dataReciever.tpss!=dataSender.tpss){ro++;Serial.print("tpss->");Serial.println(dataReciever.tpss);}
  if(dataReciever.batteryVoltage!=dataSender.batteryVoltage){ro++;Serial.print("batteryVoltage->");Serial.println(dataReciever.batteryVoltage);}
  if(dataReciever.afr1!=dataSender.afr1){ro++;Serial.print("afr1->");Serial.println(dataReciever.afr1);}
  if(dataReciever.afr2!=dataSender.afr2){ro++;Serial.print("afr2->");Serial.println(dataReciever.afr2);}
  if(dataReciever.knock!=dataSender.knock){ro++;Serial.print("knock->");Serial.println(dataReciever.knock);}
  if(dataReciever.egocor1!=dataSender.egocor1){ro++;Serial.print("egocor1->");Serial.println(dataReciever.egocor1);}
  if(dataReciever.egocor2!=dataSender.egocor2){ro++;Serial.print("egocor2->");Serial.println(dataReciever.egocor2);}
  if(dataReciever.aircor!=dataSender.aircor){ro++;Serial.print("aircor->");Serial.println(dataReciever.aircor);}
  if(dataReciever.warmcor!=dataSender.warmcor){ro++;Serial.print("warmcor->");Serial.println(dataReciever.warmcor);}
  if(dataReciever.accelEnrich!=dataSender.accelEnrich){ro++;Serial.print("accelEnrich->");Serial.println(dataReciever.accelEnrich);}
  if(dataReciever.tpsfuelcut!=dataSender.tpsfuelcut){ro++;Serial.print("tpsfuelcut->");Serial.println(dataReciever.tpsfuelcut);}
  if(dataReciever.baroCorrection!=dataSender.baroCorrection){ro++;Serial.print("baroCorrection->");Serial.println(dataReciever.baroCorrection);}
  if(dataReciever.gammaEnrich!=dataSender.gammaEnrich){ro++;Serial.print("gammaEnrich->");Serial.println(dataReciever.gammaEnrich);}
  if(dataReciever.ve1!=dataSender.ve1){ro++;Serial.print("ve1->");Serial.println(dataReciever.ve1);}
  if(dataReciever.ve2!=dataSender.ve2){ro++;Serial.print("ve2->");Serial.println(dataReciever.ve2);}
  if(dataReciever.iacstep!=dataSender.iacstep){ro++;Serial.print("iacstep->");Serial.println(dataReciever.iacstep);}
  if(dataReciever.cold_adv_deg!=dataSender.cold_adv_deg){ro++;Serial.print("cold_adv_deg->");Serial.println(dataReciever.cold_adv_deg);}
  if(dataReciever.TPSdot!=dataSender.TPSdot){ro++;Serial.print("TPSdot->");Serial.println(dataReciever.TPSdot);}
  if(dataReciever.MAPdot!=dataSender.MAPdot){ro++;Serial.print("MAPdot->");Serial.println(dataReciever.MAPdot);}
  if(dataReciever.dwell!=dataSender.dwell){ro++;Serial.print("dwell->");Serial.println(dataReciever.dwell);}
  if(dataReciever.MAFFF!=dataSender.MAFFF){ro++;Serial.print("MAFFF->");Serial.println(dataReciever.MAFFF);}
  if(dataReciever.fuelload!=dataSender.fuelload){ro++;Serial.print("fuelload->");Serial.println(dataReciever.fuelload);}
  if(dataReciever.fuelcor!=dataSender.fuelcor){ro++;Serial.print("fuelcor->");Serial.println(dataReciever.fuelcor);}
  if(dataReciever.portStatus!=dataSender.portStatus){ro++;Serial.print("portStatus->");Serial.println(dataReciever.portStatus);}
  if(dataReciever.knockRetard!=dataSender.knockRetard){ro++;Serial.print("knockRetard->");Serial.println(dataReciever.knockRetard);}
  if(dataReciever.EAEfcor1!=dataSender.EAEfcor1){ro++;Serial.print("EAEfcor1->");Serial.println(dataReciever.EAEfcor1);}
  if(dataReciever.egoV1!=dataSender.egoV1){ro++;Serial.print("egoV1->");Serial.println(dataReciever.egoV1);}
  if(dataReciever.egoV2!=dataSender.egoV2){ro++;Serial.print("egoV2->");Serial.println(dataReciever.egoV2);}
  if(dataReciever.amcUpdates!=dataSender.amcUpdates){ro++;Serial.print("amcUpdates->");Serial.println(dataReciever.amcUpdates);}
  if(dataReciever.kpaix!=dataSender.kpaix){ro++;Serial.print("kpaix->");Serial.println(dataReciever.kpaix);}
  if(dataReciever.EAEfcor2!=dataSender.EAEfcor2){ro++;Serial.print("EAEfcor2->");Serial.println(dataReciever.EAEfcor2);}
  if(dataReciever.spare1!=dataSender.spare1){ro++;Serial.print("spare1->");Serial.println(dataReciever.spare1);}
  if(dataReciever.spare2!=dataSender.spare2){ro++;Serial.print("spare2->");Serial.println(dataReciever.spare2);}
  if(dataReciever.trig_fix!=dataSender.trig_fix){ro++;Serial.print("trig_fix->");Serial.println(dataReciever.trig_fix);}
  if(dataReciever.spare4!=dataSender.spare4){ro++;Serial.print("spare4->");Serial.println(dataReciever.spare4);}
  if(dataReciever.spare5!=dataSender.spare5){ro++;Serial.print("spare5->");Serial.println(dataReciever.spare5);}
  if(dataReciever.spare6!=dataSender.spare6){ro++;Serial.print("spare6->");Serial.println(dataReciever.spare6);}
  if(dataReciever.spare7!=dataSender.spare7){ro++;Serial.print("spare7->");Serial.println(dataReciever.spare7);}
  if(dataReciever.spare8!=dataSender.spare8){ro++;Serial.print("spare8->");Serial.println(dataReciever.spare8);}
  if(dataReciever.spare9!=dataSender.spare9){ro++;Serial.print("spare9->");Serial.println(dataReciever.spare9);}
  if(dataReciever.spare10!=dataSender.spare10){ro++;Serial.print("spare10->");Serial.println(dataReciever.spare10);}
  if(dataReciever.tachCount!=dataSender.tachCount){ro++;Serial.print("tachCount->");Serial.println(dataReciever.tachCount);}
  if(dataReciever.ospare!=dataSender.ospare){ro++;Serial.print("ospare->");Serial.println(dataReciever.ospare);}
  if(dataReciever.cksum!=dataSender.cksum){ro++;Serial.print("cksum->");Serial.println(dataReciever.cksum);}
  if(dataReciever.deltaT!=dataSender.deltaT){ro++;Serial.print("deltaT->");Serial.println(dataReciever.deltaT);}


  
  if (ro){
    Serial.println("Que fill de puta!");
    Serial.println(ro);
   
  }else{
    Serial.println("PUTISSMU AMO");
  }    
}

int llegirposicio(int bytes, int np,int divider, char respuesta[50]){
  
  int resposta=0;
  int nb,ni;
  bool bbp;
  ni=bytes*8;
  
  
      nb=7; //posición bit dentro del byte que lees
      
      while(ni>0){
        if(nb==0){
          bbp=bitRead(respuesta[np],nb);
          bitWrite(resposta,ni-1,bbp);
      //    Serial.print(bbp);
          nb=7;
          np=np+1; //cuidado con esto. Modificar también este
          ni--;
        }
        else{
          bbp=bitRead(respuesta[np],nb);
      //    Serial.print(bbp);
          bitWrite(resposta,ni-1,bbp);
          nb--;
          ni--;
        }
      }
      resposta=resposta/divider; //operador aplicado según documento "Megasquirt Serial Protocol"
   
     return resposta;
  }
