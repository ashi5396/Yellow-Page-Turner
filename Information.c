#include "information.h"

void runApp() {
	FILE *infile = NULL;
	char line[1000] = "";
	char firstName[100] = "";
	char lastName[100] = "";
	char phoneNumber[12] = "";
	char temp[1000] = "";
	Infor information[10];
	int i = 0;
	infile = fopen("information.txt", "r");

	if (infile == NULL) {
		printf("Sorry the file did not open successfully. Check it again\n");
	}

	else {
		//extract information from the file
		while (!feof(infile)) {
			fgets(line, 1000, infile);
			strcpy(firstName, strtok(line, ","));
			strcpy(lastName, strtok(NULL, ","));
			strcpy(phoneNumber, strtok(NULL, "\n"));

			//copy information into the struct array
			strcpy(information[i].firstName, firstName);
			strcpy(information[i].lastName, lastName);
			strcpy(information[i].phoneNumber, phoneNumber);
			i++;
		}
	}
	
	int option = 0;
	do {
		//let the user chose an option
		printf("Welcome to the Yellow Page Turner\n");
		printf("Please chose an option from below\n");
		printf("1.Search by first name\n");
		printf("2.Search by last name\n");
		printf("3.Search by phone number\n");
		scanf("%d", &option);
		switch (option) {
		case 1:
			system("CLS");
			int success = searchFirstName(information);
			if (success == 0) {
				printf("Sorry couldn't find anything\n\n");
			}
			break;
		case 2:
			system("CLS");
			int secondSuccess = searchLastName(information);
			if (secondSuccess == 0) {
				printf("Sorry couldn't find anything\n\n");
			}
			break;
		default:
			system("CLS");
			int thirdSuccess = searchPhone(information);
			if (thirdSuccess == 0) {
				printf("Sorry couldn't find anything\n\n");
			}
			break;
		}
		
	} while (option != 3);

}

void printData(Infor information[]) {
	for (int i = 0; i < 2; i++) {
		printf("%s\n", information[i].firstName);
	}
}

int searchFirstName(Infor information[]) {
	char search[100];
	char secondSearch[100];
	Infor secondInfor[10];

	int j = 1, i = 0, k = 0, searchResult = 0, success =0;
	printf("Please enter the first name to search\n\n");
	scanf("%s", search);
	//printf("%c", toupper(search[0]));

	//go through the list and print out the names that matches
	
	
	//for (int l = 0; l<5; l++) {
	//	for (int m = 0; information[l].firstName[m] != '\0'; m++) {
	//		secondInfor[l].firstName[m] = toupper(information[l].firstName[m]);
	//	}
	//}
	//int r = 0;
	//while (search[r]) {
	//	secondSearch[r] = toupper(search[r]);
	//	r++;
	//}
	//
	//while (i < 5) {

	//	if (strcmp(secondInfor[i].firstName, secondSearch) == 0) {
	//		printf("%d %s %s\n", j, information[i].firstName, information[i].lastName);
	//		j++;
	//		success = 1;
	//	}
	//	i++;
	//}
	//
	//if (j == 2) {
	//	searchResult = 1;
	//}
	//else if(j>2) {
	//	searchResult = j - 1;
	//}
	//
	//if (searchResult > 1) {
	//	char firstName[100], lastName[100];
	//	printf("Please enter the first name and the last name with a space in between\n");
	//	scanf("%s %s", firstName, lastName);
	//	for (int k = 0; k < 5; k++) {
	//		if (strcmp(information[k].firstName, firstName) == 0 && strcmp(information[k].lastName, lastName) == 0) {
	//			printf("Name:%s %s Phone Number:%s \n\n", information[k].firstName, information[k].lastName, information[k].phoneNumber);
	//		}
	//	}
	//}
	//else if (searchResult == 1) {
	//	for (int m = 0; m < 5; m++) {
	//		if (strcmp(information[m].firstName, search) == 0) {
	//			printf("Name:%s %s Phone Number:%s \n\n", information[m].firstName, information[m].lastName, information[m].phoneNumber);
	//		}
	//	}
	//}

	return success;
}

int searchLastName(Infor information[]) {
	char search[100];
	int j = 1, i = 0, k = 0, searchResult = 0, success=0;
	printf("Please enter the last name to search\n");
	scanf("%s", search);
	//go through the list and print out the names that matches
	while (i < 5) {
		if (strcmp(information[i].lastName, search) == 0) {
			printf("%d %s %s\n\n", j, information[i].firstName, information[i].lastName);
			j++;
			success = 1;
		}
		i++;
	}

	if (j == 2) {
		searchResult = 1;
	}
	else if (j>2) {
		searchResult = j - 1;
	}

	if (searchResult > 1) {
		char firstName[100], lastName[100];
		printf("Please enter the first name and the last name with a space in between\n");
		scanf("%s %s", firstName, lastName);
		for (int k = 0; k < 5; k++) {
			if (strcmp(information[k].firstName, firstName) == 0 && strcmp(information[k].lastName, lastName) == 0) {
				printf("Name:%s %s Phone Number:%s \n\n", information[k].firstName, information[k].lastName, information[k].phoneNumber);
			}
		}
	}
	else if (searchResult == 1) {
		for (int m = 0; m < 5; m++) {
			if (strcmp(information[m].lastName, search) == 0) {
				printf("Name:%s %s Phone Number:%s \n\n", information[m].firstName, information[m].lastName, information[m].phoneNumber);
			}
		}
	}
	return success;
}

int searchPhone(Infor information[]) {
	char phone[20];
	int success = 0;
	printf("Please enter the phone number you want find information on\n");
	scanf("%s", phone);
	for (int i = 0; i < 5; i++) {
		if (strcmp(information[i].phoneNumber, phone) == 0) {
			printf("First Name: %s  Last Name: %s Phone Number: %s\n", information[i].firstName, information[i].lastName, information[i].phoneNumber);
			success = 1;
		}
	}
	return success;
}