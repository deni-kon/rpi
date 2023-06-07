#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>
#define uchar unsigned char
#define led_pin_red 0		// GPIO17
#define led_pin_green 1		// GPIO18
#define led_pin_blue 2		// GPIO27


void ledInit(void)
{
	softPwmCreate(led_pin_red, 0, 100);
	softPwmCreate(led_pin_green, 0, 100);
	softPwmCreate(led_pin_blue, 0, 100);
}

int initialize(void)
{
	if(wiringPiSetup() == -1)
	{
		printf("setup wiringPi failed");
		return 0;
	}
	ledInit();
	return 1;
}

void ledSet(uchar r_val, uchar g_val, uchar b_val)
{
	softPwmWrite(led_pin_red, r_val);
	softPwmWrite(led_pin_green, g_val);
	softPwmWrite(led_pin_blue, b_val);
}

int main(void)
{
	int ms = 1500;

	if (initialize() == 0)
		return 1;

	ledSet(0xff, 0x00, 0x00);	
	delay(ms);
	ledSet(0x00, 0xff, 0x00);	
	delay(ms);
	ledSet(0x00, 0x00, 0xff);	
	delay(ms);
	ledSet(0xff, 0xff, 0x00);	
	delay(ms);
	ledSet(0xff, 0x00, 0xff);	
	delay(ms);
	ledSet(0x00, 0xff, 0xff);	
	delay(ms);
	return 0;
}
