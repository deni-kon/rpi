#include <wiringPi.h>
#include <stdio.h>

#define BeepPin 0

int main(void){
    if(wiringPiSetup() == -1){
        printf("setup wiringPi failed !");
        return 1;
    }
    
    pinMode(BeepPin, OUTPUT);   //set GPIO0 output
    while(1)
    {
        //beep on
        printf("Buzzer on\n");
        digitalWrite(BeepPin, LOW);
        delay(300);
        printf("Buzzer off\n");
        //beep off
        digitalWrite(BeepPin, HIGH);
        delay(3000);
    }
    return 0;
}

