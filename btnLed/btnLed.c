/*****************************************************************************
*  Filename        : btnLed.c
*  Original Author : SunFounder Electronics
*  Modified By     : Eric McDaniel
*  Date            : November 9th, 2018
*  Description     : This file was originally sourced from SunFounder
*  		     Electronics, Sensor Kit V2.0 for Raspberry Pi B+
*                    The original code was only for "Lesson 2", which
*  		     would light an LED bulb only if a button was pressed.
* 		     The only adjustment was which GPIO pin to use, as the
*  		     original ones will be occuped by other sensors.
*****************************************************************************/
#include <wiringPi.h>
#include <stdio.h>

#define LedPin    2 // GPIO #27
#define ButtonPin 1 // GPIO #18

/**
* The method below, if properly called, demonstrates that the program
* isn't designed within the paradigm of event-driven programming, but
* is simple an illusion of event-driven programming by using an infinite
* loop and at iteration within every fraction of a second, the main method
* checks to see if the button is pressed or not. This happens so fast that
* it creates an illusion of responding to user activity.
*/
void proofAgainstEventDrivenProgramming(float x)
{
	printf("Iteration Counter: %.0f\n", x);
}

int main(void)
{
	if(wiringPiSetup() == -1)
	{
		printf("Setup of wiringPi has failed.");
		return 1; 
	}
	
	pinMode(LedPin, OUTPUT); 
	pinMode(ButtonPin, INPUT);
	pullUpDnControl(ButtonPin, PUD_UP);
	
	printf("The Button LED program is active!\n\t(Press CTRL + C to exit the program)\n");
	
	float x = 0;
	while(1)
	{
		digitalWrite(LedPin, HIGH);
		
		if(digitalRead(ButtonPin) == 0)
			digitalWrite(LedPin, LOW); // LED on
			
		/* Uncomment the code below for proof that this is just an insanely fast loop
		   and not a true/ efficient form of event driven programming. */
		   
		//proofAgainstEventDrivenProgramming(x);
		//x += 1;
	}
	return 0;
}  // end main()
