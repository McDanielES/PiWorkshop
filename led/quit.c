
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
	digitalWrite(LedPin, HIGH);  //led off
	return 0;
}
