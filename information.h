#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct information {
	char lastName[100];
	char firstName[100];
	char phoneNumber[12];
}Infor;

void runApp();
void printData(Infor information[]);
int searchFirstName(Infor information[]);
int searchLastName(Infor information[]);