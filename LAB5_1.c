/*
 ============================================================================
 Name        : LAB5_1.c
 Author      : Katherine Rac
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


int main(void){
        wiringPiSetupGpio(); //
        pinMode(17 ,OUTPUT); //
        pinMode(27 ,OUTPUT); //
        srand(time(0));
        for(;;)
        {
            digitalWrite(17, HIGH);
            delay(rand()%1001+500);
            digitalWrite(17, LOW);
            digitalWrite(27, HIGH);
            delay(rand()%1001+500);
            digitalWrite(27, LOW);
        }
    return 0;
}

