/* -------------------------RELAY-------------------------------*/
 // When looking at the relay, with the 3 pins in front of you, 
 // the 2 pins to connect are the 2 left pins
 const int dustPin =  2; 

 /* -------------------------SENSOR HALL EFFECT---------------------------*/
#define SENSOR_NUMBER 3
const int hallPin[SENSOR_NUMBER] = {
	3/* miter saw*/, 
	4/* workbench*/, 
	5/* table saw */
};

/* -------------------------BUTTONS -------------------------------------*/
// It has a debounce condensator/capacitor 10nF (marked 103J 103G 103M 103K) plugged in parallel to button pins
// It has a 20K resistor (virtual, not visible because inside arduino) connected to it due to the use of INPUT_PULLUP
// So it is HIGH when it is open.
#define BUTTON_NUMBER 1
const int buttonPin[BUTTON_NUMBER] = {6/*bouton pres de scie table*/};

const int ledPin =  13; 

/* -------------------------SETUP -------------------------------------*/
void setup() {
	Serial.begin(115200);
	// initialize the LED pin as an output:
	pinMode(ledPin, OUTPUT); 
	// initialize the DUST COLLECTOR pin as an output:
	pinMode(dustPin, OUTPUT); 
	
	for (int i = 0; i < SENSOR_NUMBER; i++) {  
		pinMode(hallPin[i], INPUT);     
	}
	for (int j = 0; j < BUTTON_NUMBER; j++) {  
		pinMode(buttonPin[j], INPUT_PULLUP);     
	}
}
/* -------------------------LOOP -------------------------------------*/

void loop(){
  bool oneIsOn = false;
	for (int i = 0; i < SENSOR_NUMBER; i++) { 
		bool state = digitalRead(hallPin[i]);
		if (state == LOW) {    
			oneIsOn = true;
			Serial.print("SENSOR D");
			Serial.println(hallPin[i]);
		}		
	}
	                                        
	for (int j = 0; j < BUTTON_NUMBER; j++) {  
		bool state = digitalRead(buttonPin[j]);
		if (state == LOW) {
			oneIsOn = true;
			Serial.print("BUTTON D");
			Serial.println(buttonPin[j]);
		}
	}
	
  if (oneIsOn) {     
    // turn LED on:    
    digitalWrite(ledPin, HIGH);  
	// turn dust collector on
    digitalWrite(dustPin, LOW);
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW); 
	// turn dust collector off
    digitalWrite(dustPin, HIGH);  
  }
  
  // Avoid too fast switching that can cause damage to the dust collector

  delay(1000);
}
