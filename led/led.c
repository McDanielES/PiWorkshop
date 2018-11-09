/*****************************************************************************
*  Filename        : led.c
*  Original Author : SunFounder Electronics
*  Modified By     : Eric McDaniel
*  Date            : November 9th, 2018
*  Description     : This file was originally sourced from SunFounder
* 				     Electronics, Sensor Kit V2.0 for Raspberry Pi B+
*                    The original code was only for "Lesson 1", which
*  				     would blink an LED bulb on and off every half
* 					 second. The only adjustment was the timing and 
* 					 how many times it would print to the terminal.
* 
*****************************************************************************/
#include <wiringPi.h>
#include <stdio.h>

#define  LedPin    2

int main(void)
{
	if (wiringPiSetup() == -1)
	{
		printf("setup wiringPi failed !");
		return 1; 
	}
	
	pinMode(LedPin, OUTPUT);	
	int x = 0;

	while (x < 5)
	{
		digitalWrite(LedPin, LOW);  //led on
		printf("led on...\n");
		delay(300);
		digitalWrite(LedPin, HIGH);  //led off
		printf("...led off\n");
		delay(300);
		++x;
	}
	printf("You get the idea...\n\t(Press CTRL + C to Exit)\n\n");	
	while (1)
	{
		digitalWrite(LedPin, LOW);
		delay(300);
		digitalWrite(LedPin, HIGH);
		delay(300);		
	}
	return 0;
}
