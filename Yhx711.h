/*
 * Yhx711.h
 *
 *  Created on: Oct 25, 2016
 *      Author: nucleus
 */

#ifndef YHX711_H_
#define YHX711_H_

#include "Arduino.h"

class YHx711
{
public:
	YHx711(uint8_t pin_din, uint8_t pin_slk);
	virtual ~YHx711();
	long getValue();
	long averageValue(byte times = 1);
	void setMode(byte mode);
	

private:
	const uint8_t _pin_dout;
	const uint8_t _pin_slk;
	byte puls = 1;
};

#endif /* YHX711_H_ */
