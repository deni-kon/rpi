#include <wiringPi.h>
#include <stdio.h>

int pins[10] = {0,1,2,3,4,5,6,8,9,10};

int initialize(void)
{
	if(wiringPiSetup() == -1) {
		printf("setup wiringPi failed");
		return 0;
	}
	for(int i=0; i<10; i++)
	{
		pinMode(pins[i], OUTPUT);
	}

	return 1;
}

void switchLED(int led_pin, int isOn)
{
	if (isOn == 1)
	{
		digitalWrite(led_pin, LOW);
	}
	else
	{
		digitalWrite(led_pin, HIGH);
	}
}

int main(void)
{
	if (initialize() == 0)
		return 1;

	for(int i=0; i<10; i++) switchLED(pins[i], 0);
	delay(300);
	for(int i=0; i<10; i++)
	{
		switchLED(pins[i], 1);
		delay(200);
	}

	for(int i=0; i<5; i++)
	{
		for(int i=0; i<10; i++)
		{
			switchLED(pins[i], 0);
		}
		delay(500);
		for(int i=0; i<10; i++)
		{
			switchLED(pins[i], 1);
		}
		delay(500);
	}
	return 0;
}

