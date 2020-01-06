#include "cle_thunderborg.h"
ThunderBorg TBC1;							// Klasse initialisieren als TBC1 

// Anregungen gerne im Github als Fragen (issues) oder per Mail an pr@cle.ch


void setup() {
	TBC1.Init(0x15);							// Intit Thunderborg
};


void loop(){
  // Fange rückwärts an und fahre langsam immer schneller vorwärts.
  for (int i =-255; i<=255;i++){
    TBC1.SetMotors(i,i);
    delay(5);
  };
 
  // Fange vorwärts an und fahre langsam immer schneller rückwärts.
  for (int i =255; i>=-255;i--){
    TBC1.SetMotors(i,i);
     delay(5);
  };
};