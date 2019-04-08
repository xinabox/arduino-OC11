/*
	This is a library for the OC11
	Mechanical Relay

	The board uses I2C for communication.
	The board communicates with the following I2C device:
	* 	PCA9554A
	
	Data Sheets:
	PCA9554A - http://www.ti.com/lit/ds/symlink/pca9554a.pdf
*/

#include <xOC11.h>

/********************************************************
 	Constructor
*********************************************************/
xOC11::xOC11()
{
	PCA9554A_I2C_ADDRESS = 0x38;
}

xOC11::xOC11(uint8_t addr)
{
	PCA9554A_I2C_ADDRESS = addr;
}

/********************************************************
 	Configure OC11
*********************************************************/
bool xOC11::begin(void)
{
	begin(PCA9554A_ALL_OUTPUTS_OFF);
}

bool xOC11::begin(bool state)
{
	digitalWrite(CH0,state);
	digitalWrite(CH1,state);
	xCore.write8(PCA9554A_I2C_ADDRESS, PCA9554A_REG_CONFIG, PCA9554A_CONF_OUTPUT);
	return true;
}

bool xOC11::begin(bool state_1, bool state_2)
{
	digitalWrite(CH0,state_1);
	digitalWrite(CH1,state_2);
	xCore.write8(PCA9554A_I2C_ADDRESS, PCA9554A_REG_CONFIG, PCA9554A_CONF_OUTPUT);
	return true;
}

/********************************************************
 	Write to PIN
*********************************************************/
void xOC11::digitalWrite(uint8_t channel, bool state)
{	
	uint8_t port_status = getStatus();

	if(state == true){
		port_status |= (1 << channel);
		xCore.write8(PCA9554A_I2C_ADDRESS, PCA9554A_REG_OUTPUT_PORT, port_status);
	}else if(state == false){
		port_status &= ~(1 << channel);
		xCore.write8(PCA9554A_I2C_ADDRESS, PCA9554A_REG_OUTPUT_PORT, port_status);
	}
}

/********************************************************
 	Get output pin Status
*********************************************************/
uint8_t xOC11::getStatus(void)
{
	uint8_t pin_state = xCore.read8(PCA9554A_I2C_ADDRESS, PCA9554A_REG_OUTPUT_PORT); 
	return pin_state;
}



