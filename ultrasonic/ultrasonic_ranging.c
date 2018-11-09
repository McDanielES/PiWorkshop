/*****************************************************************************
*  Filename        : ultrasonic_ranging.c
*  Original Author : SunFounder Electronics
*  Modified By     : Eric McDaniel
*  Date            : November 9th, 2018
*  Description     : This file was originally sourced from SunFounder
* 				     Electronics, Sensor Kit V2.0 for Raspberry Pi B+
*                    The original code was only for "Lesson 25", which
*  				     would print to the console the distance reading
* 				     from the ultrasonic sensor. This source was modified
* 					 to accomodate an LED in GPIO 27 which would strobe
* 					 within a predefined distance.
* 
*****************************************************************************/
#include <wiringPi.h>
#include <stdio.h>
#include <sys/time.h>

#define  DISTANCE 20 // Trigger alarm in centimeters 
#define  Trig      0 // GPIO #17
#define  Echo      1 // GPIO #18
#define  LedPin    2 // GPIO #27

void ultraInit(void)
{
	pinMode(Echo, INPUT);
	pinMode(Trig, OUTPUT);
}

float disMeasure(void)
{
	struct timeval tv1;
	struct timeval tv2;
	long time1, time2;
    float dis;

	digitalWrite(Trig, LOW);
	delayMicroseconds(2);

	digitalWrite(Trig, HIGH);
	delayMicroseconds(10);
	digitalWrite(Trig, LOW);
								
	while(!(digitalRead(Echo) == 1));
	gettimeofday(&tv1, NULL);

	while(!(digitalRead(Echo) == 0));
	gettimeofday(&tv2, NULL);

	time1 = tv1.tv_sec * 1000000 + tv1.tv_usec;
	time2  = tv2.tv_sec * 1000000 + tv2.tv_usec;

	dis = (float)(time2 - time1) / 1000000 * 34000 / 2;

	return dis;
}

int main(void)
{
	float dis;
	int input;

	if(wiringPiSetup() == -1)
	{
		printf("setup wiringPi failed !");
		return 1; 
	}

	ultraInit();
	//printf("Please enter the distance in cm to trigger alarm: ");
	//scanf("%d", &input);	
	printf("\nHome security device is now active!\n(Press CTRL + C to exit)\n\n");
	
	dis = disMeasure();
	int isSafe = 0;
	
	while(1)
	{
		if (dis < DISTANCE) // replace with: input
		{
			printf("ALERT: Object detected within %0.2f centimeters!\n", dis);
			digitalWrite(LedPin, LOW);  // LOW = LED is on
			delay(200);
			digitalWrite(LedPin, HIGH); // HIGH = LED is off
			delay(200);
			isSafe = 1;
		}
		else
		{
			if (isSafe == 1)
				printf("\tObject has cleared the range of %d centimeters.\n\n", DISTANCE); // replace with: input
			delay(300);
			isSafe = 0;
		}
		dis = disMeasure();
	}
	return 0;
}
