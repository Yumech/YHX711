/*
 * Yhx711.cpp
 *
 *  Created on: Oct 25, 2016
 *      Author: nucleus
 */

#include "Yhx711.h"

YHx711::YHx711(uint8_t pin_dout, uint8_t pin_slk) :
		_pin_dout(pin_dout), _pin_slk(pin_slk)
{
	pinMode(_pin_slk, OUTPUT);
	pinMode(_pin_dout, INPUT);

	digitalWrite(_pin_slk, HIGH);
	delayMicroseconds(100);
	digitalWrite(_pin_slk, LOW);
	
	getValue();


}

void YHx711::setMode(byte mode) {
	switch (mode) {
		case 1:		// channel A, gain factor 128
			puls = 1;
			break;
		case 2:		// channel B, gain factor 32
			puls = 2;
			break;
		case 3:	        // channel A, gain factor 64	
			puls = 3;
			break;

	}

	digitalWrite(_pin_slk, LOW);
	getValue();
}

YHx711::~YHx711()
{

}

long YHx711::averageValue(byte times)
{
	long sum = 0;
	for (byte i = 0; i < times; i++)
	{
		sum += getValue();
	}

	return sum / times;
}

long YHx711::getValue()
{
	byte data[3];

	while (digitalRead(_pin_dout))
		;

	for (byte j = 3; j--;)
	{
		for (char i = 8; i--;)
		{
			digitalWrite(_pin_slk, HIGH);
			bitWrite(data[j], i, digitalRead(_pin_dout));
			digitalWrite(_pin_slk, LOW);
		}
	}

	
	for (unsigned int i = 0; i < puls; i++) {
		digitalWrite(_pin_slk, HIGH);
		digitalWrite(_pin_slk, LOW);
	}
		
	
	

	data[2] ^= 0x80;

	return ((uint32_t) data[2] << 16) | ((uint32_t) data[1] << 8)
			| (uint32_t) data[0];
}



