/* -------------------------------------------
Name:Louie Tse
Student number:027168103
Email:lttse@myseneca.ca
Section:SUU
Date:December 22,2017
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "contactHelpers.h"
#include "contacts.h"
#define MAXCONTACTS 5

// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):

//------------------------------------------------------
// Function Definitions
//------------------------------------------------------
// clearKeyboard function definition

//will clear anything left in buffer that's not scan
//e.g. if char[8] but input 123456789
//it will read up to number 7 with scanf("%7s", &variable) plus \0 terminator --> 1234567\0
//then calling clearKeyboard() will clear "8,9" and whatever after "\n"
void clearKeyboard(void)
{
	while (getchar() != '\n') {}
}
// pause function definition goes here:
void pause() {
	printf("(Press Enter to Continue)");
	clearKeyboard();
}
// getInt function definition goes here:
int getInt(void) {
	int Value = 0;
	char NL = 'x';
	scanf("%d%c", &Value, &NL);
	while (NL != '\n') {
		printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		clearKeyboard();
		scanf("%d%c", &Value, &NL);
	}
	return Value;
}

// getIntInRange: Empty function definition goes here:
int getIntInRange(int Min, int Max) {
	int Values = -1;
	while (Values < Min || Values > Max) {
		Values = getInt();
		if (Values < Min || Values > Max) {
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", Min, Max);
		}
	}
	return Values;
}

// yes: Empty function definition goes here:
int yes(void) {
	char option;
	int rtn = 0;
	char newLine = 'x';

	scanf("%1c%c", &option, &newLine);
	
	while ( newLine != '\n' && (option != 'Y' || option != 'y' || option != 'N' || option != 'n') ) {
		clearKeyboard();
		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		scanf("%1s%c", &option, &newLine);
	}

	if (option == 'Y' || option == 'y') {
		rtn = 1;
	}
	return rtn;
}
// menu: Empty function definition goes here:
int menu(void) {
	int selection;
	printf("Contact Management System\n"
		"-------------------------\n"
		"1. Display contacts\n"
		"2. Add a contact\n"
		"3. Update a contact\n"
		"4. Delete a contact\n"
		"5. Search contacts by cell phone number\n"
		"6. Sort contacts by cell phone number\n"
		"0. Exit\n\n");

	// Capture input to option variable
	printf("Select an option:> ");
	selection = getIntInRange(0, 6);
	printf("\n");
	return selection;
}

// ContactManagerSystem:
void ContactManagerSystem(void) {
	struct Contact testContacts[MAXCONTACTS] = { { { "Rick",{ '\0' }, "Grimes" },
													{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
													{ "4161112222", "4162223333", "4163334444" } },
													{ 
														{ "Maggie", "R.", "Greene" },
													{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
													{ "9051112222", "9052223333", "9053334444" } },
													{ 
														{ "Morgan", "A.", "Jones" },
													{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
													{ "7051112222", "7052223333", "7053334444" } },
													{ 
													{ "Sasha",{ '\0' }, "Williams" },
													{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
													{ "9052223333", "9052223333", "9054445555" } }, };
	

	char userInput = 0;
	int selection = -1;
	int exit = -1;
	while (exit == -1) {
		selection = menu();
		switch (selection) {
			case 0:
				printf("Exit the program? (Y)es/(N)o: ");
				scanf("%c", &userInput);
				if (userInput == 'Y' || userInput == 'y') {
					printf("\nContact Management System: terminated\n");
					exit = 1;
				}
				else {
					printf("\n");
					//ContactManagerSystem();
				}
				break;
			case 1: // Display Contacts
				displayContacts(testContacts, MAXCONTACTS);
				pause();
				printf("\n");
				//ContactManagerSystem();
				break;
			case 2:	// Add a Contact
				addContact(testContacts, MAXCONTACTS);
				pause();
				printf("\n");
				//ContactManagerSystem();
				break;
			case 3:	// Update a Contact
				updateContact(testContacts, MAXCONTACTS);
				pause();
				printf("\n");
				break;
			case 4:	// Delete a Contact
				deleteContact(testContacts, MAXCONTACTS);
				pause();
				printf("\n");
				//ContactManagerSystem();
				break;
			case 5:	// Search contacts by cell phone number
				searchContacts(testContacts, MAXCONTACTS);
				pause();
				printf("\n");
				//ContactManagerSystem();
				break;
			case 6:	// Sort contacts by cell phone number
				printf("<<< Feature 6 is unavailable >>>\n\n");
				pause();
				printf("\n");
				//ContactManagerSystem();
				break;

			default: //Displays error
				printf("*** OUT OF RANGE *** <Enter a number between 0 and 6>: \n\n");
			}


	}
	
}

// Generic function to get a ten-digit phone number (ensures 10 chars entered)
void getTenDigitPhone(char telNum[11])
{
	int needInput = 1;

	while (needInput == 1) {
		scanf("%10[^\n]", telNum);
		clearKeyboard();

		// (String Length Function: validate entry of 10 characters)
		if (strlen(telNum) == 10 ) {
			needInput = 0;
		}
		else {
			
			printf("Enter a 10-digit phone number: ");
		}
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[11])
{
	int i = 0;

	for (i = 0; i < size; i++) {
		if (strcmp(cellNum, contacts[i].numbers.cell) == 0) {
			return i;
		}
	}
	return -1;
}

// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void) {
	printf("+-----------------------------------------------------------------------------+\n"
		"|                              Contacts Listing                               |\n"
		"+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
void displayContactFooter(int totalContacts) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", totalContacts);
}

// displayContact:
void displayContact(const struct Contact* contact) {
	if (strcmp(contact->name.middleInitial, "") == 0) {
		printf(" %s %s\n", contact->name.firstName, contact->name.lastName);
	}
	else {
		printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
	}
	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
	printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
	if (contact->address.apartmentNumber != 0) {
		printf("Apt# %d, ", contact->address.apartmentNumber);
	}
	
	printf("%s, %s\n", contact->address.city, contact->address.postalCode);
	
}

// displayContacts:
void displayContacts(const struct Contact*contact, int size) {
	int i = 0;
	int total = 0;
	displayContactHeader();
	for(i = 0; i < size; i++){
		if (strlen(contact[i].numbers.cell) > 0){
			displayContact(&contact[i]);
			total++;
		}
	}
	displayContactFooter(total);
}

// searchContacts:
void searchContacts(const struct Contact*contact, int size) {
	int foundIndex = -1; //set found to false
	char userNum[11];

	//ask user for input
	printf("Enter the cell number for the contact: ");
	//call function to check if the number is a 10 digit number
	getTenDigitPhone(userNum);
	
	//use findContactIndex() to check if the contact with the number exist
	foundIndex = findContactIndex(contact, size, userNum);

	//if found does not equal to defaut value (not found)
	//then display the contact information
	//else say not found
	if (foundIndex != -1) {
		printf("\n");
		displayContact(&contact[foundIndex]);
		printf("\n");
	}
	else {
		printf("*** Contact NOT FOUND ***\n");
	}
		
}

// addContact:
void addContact(struct Contact * contact, int size) {
	int i, len;

	//go through each contact cell number as long as it's within the size limit
	for (i = 0; i < size; i++) {
		//get the length of the cellphone number
		len = strlen(contact[i].numbers.cell);
		//if cell phone number does not exist (aka empty contact)
		if (len == 0) {
			//ask for new contact info and save in the empty contact index
			getContact(&contact[i]);
			printf("--- New contact added! ---\n");
			break;
		}
		
	}
	//since the i in above forloop will add 1 after each statement, 
	//i will stop after checking condidtion i < size
	//hence i will equal to how many item is in the contact list

	//if i == maxSize given 
	//print error message
	if (i == size) {
		printf("*** ERROR: The contact list is full! ***\n");
	}
	
}

// updateContact:
void updateContact(struct Contact * contact, int size) {
	char cellNum[11];
	int foundIndex;
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNum);

	//use findContactIndex() to check if the contact with the number exist
	//findContactIndex() will return -1 if not found
	//else return the index of the contact found
	foundIndex = findContactIndex(contact, size, cellNum);

	//if a contact index is found
	if (foundIndex != -1) {
		printf("\nContact found:\n");
		//print the contact with the index found in findContactIndex()
		displayContact(&contact[foundIndex]);
		printf("\n");

		printf("Do you want to update the name? (y or n): ");
		//call fxn yes(), which will return 0 if user select no 
		//return 1 if yes is selected
		//if yes() return 1, then pass the foundIndex contact name to getName for updating the name
		if (yes() == 1) {
			getName(&contact[foundIndex].name);
		}

		printf("Do you want to update the address? (y or n): ");
		if (yes() == 1) {
			getAddress(&contact[foundIndex].address);
		}

		printf("Do you want to update the numbers? (y or n): ");
		if (yes() == 1) {
			getNumbers(&contact[foundIndex].numbers);
		}
		printf("--- Contact Updated! ---\n");
	}
	else {
		printf("*** Contact NOT FOUND ***\n");
	}

	
	
}

// deleteContact:
void deleteContact(struct Contact * contact, int size) {
	char cellNum[11];
	int foundIndex;
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNum);

	//use findContactIndex() to check if the contact with the number exist
	//findContactIndex() will return -1 if not found
	//else return the index of the contact found
	foundIndex = findContactIndex(contact, size, cellNum);

	//if a contact index is found
	if (foundIndex != -1) {
		printf("\nContact found:\n");
		//print the contact with the index found in findContactIndex()
		displayContact(&contact[foundIndex]);
		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): ");
		if (yes() == 1) {
			contact[foundIndex].numbers.cell[0] = '\0';
			printf("--- Contact deleted! ---\n");
		}
		
	}
	else {
		printf("*** Contact NOT FOUND ***\n");
	}


}
