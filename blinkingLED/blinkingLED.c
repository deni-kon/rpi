#include <wiringPi.h>
#include <stdio.h>

int initialize()
{
	if(wiringPiSetup() == -1) {
		printf("setup wiringPi failed");
		return 0;
	}
	return 1;
}

void switchLED(int isOn, int led_pin)
{
	if (isOn == 1)
	{
		digitalWrite(led_pin, LOW);
		printf("LED is on");
	}
	else
	{
		digitalWrite(led_pin, HIGH);
		printf("LED is off");
	}
}

int main(void)
{
	if (initialize() == 0)
		return 1;

	pinMode(0, OUTPUT);
	while(1) {
		switchLED(1, 0);
		delay(500);
		switchLED(0, 0);
		delay(500);
	}	
}

