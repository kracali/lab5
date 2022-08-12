/*
 ============================================================================
 Name        : LAB52.c
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
#include <pthread.h>

int A;
int Push;
int B;
int FLAG = 0;
int START = 1;
int menu;

#define PUSH 5
#define SON 13

void ThreadMENU (void *ptr){
while(1)
{

	printf("Menu");

	scanf("%c", &menu);
	if(menu == 'p'){
		FLAG = 1;
	}

	if (menu == 'r'){
		FLAG = 0;
	}

	if (menu == 's'){
		exit(0);
	}

	fflush(stdout);
	}
}

int main(void){
	wiringPiSetupGpio();
	pinMode(SON, OUTPUT);
	pinMode(PUSH, INPUT);
	A = 2;
	B = 1;
    pthread_t thread1;
    pthread_create(&thread1, NULL, (void*)&ThreadMENU, NULL);

	while(1){
		Push = digitalRead(PUSH);
		if(Push == 0 ){
			START = 0;
		}
		if(START == 0 & FLAG == 0){
				digitalWrite(SON,HIGH);
				delay(B);
				digitalWrite(SON,LOW);
				delay(A);
		}
	}
}
