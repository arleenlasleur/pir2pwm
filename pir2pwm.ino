#include <avr\wdt.h>
const byte loga[64]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,16,18,22,25,28,29,30,33,36,39,42,46,49,53,56,60,64,68,72,
77,81,86,90,95,100,105,110,116,121,127,132,138,144,150,156,163,169,176,182,189,196,203,210,218,225,233,240,248,255};

#define PIR                (10)
#define LED                (9)
#define MAX_NO_MOTION      (40000)
#define STEP_LEVEL         (30)

byte          level_led   = 0;
bool          ena_light   = 0;
unsigned long last_motion = millis(),
              last_chng   = millis();

void setup(){
  pinMode(PIR,INPUT_PULLUP);
  pinMode(LED,OUTPUT);
  wdt_enable(WDTO_2S);
}

void loop(){
  if(digitalRead(PIR)){
    ena_light=1;
    last_motion=millis();
  }
  if(millis()-last_motion>=MAX_NO_MOTION) ena_light=0;

  if(ena_light){
    if(millis()-last_chng>=STEP_LEVEL && level_led<63){
      level_led++;
      last_chng=millis();
    }
  }else{
    if(millis()-last_chng>=STEP_LEVEL && level_led>0){
      level_led--;
      last_chng=millis();
    }
  }
  analogWrite(LED,loga[level_led]);

  wdt_reset();
}
