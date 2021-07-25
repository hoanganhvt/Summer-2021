#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int randInt(int first,int Last){
	return rand() % Last + first;
}