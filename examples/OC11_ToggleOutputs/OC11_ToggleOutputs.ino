/*************************************************************
	This is an examples for the OC11
	2 channel Mechanical Relay
	
	You can buy one on our store!
	-----> https://xinabox.cc/products/OC11/
	
	This example in structs the OC11 to turn its outputs
	on and off
	
	The sensor communicates over the I2C Bus.
	
*************************************************************/

/********************* Library Includes *********************/
#include <xOC11.h> // https://github.com/xinabox/arduino-OC11
#include <xCore.h> 

/****************** Global sensor objects *******************/
xOC11 OC11;

/********************* SYSTEM VARIABLES *********************/
const int DELAY_TIME = 2000;

/*********************** Sketch Code ************************/
void setup() {	
	// Start the I2C Communication
	Wire.begin();
	
	// Start the OC10 port expander
	OC11.begin();

	Serial.println("OC11 Test");
}

void loop() {

	// turn outputs on
	for (int i = 1; i < 3; i++) {
		OC11.digitalWrite(i, HIGH);
	    delay(DELAY_TIME);	
	}

	// turn outputs off
	for (int i = 2; i > 0; i--) {
		OC11.digitalWrite(i, LOW);
	    delay(DELAY_TIME);	
	}
}
