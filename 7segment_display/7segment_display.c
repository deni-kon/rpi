#include <stdio.h>
#include <wiringPi.h>

#define SDI 0		// serial data input
#define RCLK 1		// memory clock input(STCP)
#define SRCLK 2		// shift register clock(SHCP)

int initialize(void)
{
	if(wiringPiSetup() == -1)
	{
		printf("setup wiringPi failed");
		return 0;
	}

	pinMode(SDI, OUTPUT);
	pinMode(RCLK, OUTPUT);
	pinMode(SRCLK, OUTPUT);

	digitalWrite(SDI, 0);
	digitalWrite(RCLK, 0);
	digitalWrite(SRCLK, 0);

	return 1;
}

void hc595_shift(unsigned char dat)
{
	for(int i=0; i<8; i++)
	{
		digitalWrite(SDI, 0x80 & (dat << i));
		digitalWrite(SRCLK, 1);
		delay(1);
		digitalWrite(SRCLK, 0);
	}	
	digitalWrite(RCLK, 1);
	delay(1);
	digitalWrite(RCLK, 0);
}

int main(void)
{
	if (initialize() == 0)
		return 1;

	unsigned char digits[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0xef};

	for(int i=0; i<10; i++)
	{
		hc595_shift(digits[i]);
		delay(500);		
	}
	//hc595_shift(0x00);
	return 0;
}
