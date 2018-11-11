/************************************************************************
* Compile this code BEFORE compiling and running the led.c program.
*
* This program isn't ment to be entertainable. It is simply just a
* tool to use in case the LED in the led.c program does not turn off.
* While led.c is running, if you press CTRL + C while the LED bulb
* is still running, the Pi and software will never get a chance to
* change the GPIO pin reading on the Pi, making the LED stay lit
* forever and ever and ever and ....
************************************************************************/

#include <wiringPi.h>
#include <stdio.h>

#define  LedPin    2

int main(void)
{
	if (wiringPiSetup() == -1)
	{
		printf("The setup wiringPi has failed!\n");
		printf("\tIf you properly ran led.c, I'm curious how you got here..\n");
		return 1; 
	}	
	pinMode(LedPin, OUTPUT);		
	digitalWrite(LedPin, HIGH);  //led off
	return 0;
} // end main()
