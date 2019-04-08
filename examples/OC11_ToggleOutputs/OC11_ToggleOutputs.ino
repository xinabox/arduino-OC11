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
const int DELAY_TIME = 1000;

/*********************** Sketch Code ************************/
void setup() {
  // Start the I2C Communication
  Wire.begin();

  // Start the OC10 port expander
  OC11.begin();

  Serial.println("OC11 Test");
}

void loop() {
  toggleOutput(CH0);
  toggleOutput(CH1);
}

void toggleOutput(int ch)
{
  OC11.digitalWrite(ch, HIGH);
  delay(DELAY_TIME);
  OC11.digitalWrite(ch, LOW);
  delay(DELAY_TIME);
}