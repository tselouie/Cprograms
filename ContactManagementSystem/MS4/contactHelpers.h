/* ------------------------------------------------------------------
Name:Louie Tse
Student number:027168103
Email:lttse@myseneca.ca
Section:SUU
Date:December 22,2017
---------------------------------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------------------------------
Description: This header file modularizes general helper functions to
help reduce redundant coding for common repetative tasks.
---------------------------------------------------------------------*/

#include "contacts.h"

//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// Clear the standard input buffer
void clearKeyboard(void);
// pause:
// Put function prototype below:
void pause(void);
// getInt:
// Put function prototype below:
int getInt(void);
// getIntInRange:
// Put function prototype below:
int getIntInRange(int, int);
// yes:
// Put function prototype below:
int yes(void);
// menu:
// Put function prototype below:
int menu(void);
// ContactManagerSystem:
// Put function prototype below:
void ContactManagerSystem(void);

// Generic function to get a ten-digit phone number
void getTenDigitPhone(char *telNum);

// findContactIndex (provided for you)
int findContactIndex(const struct Contact*, int, const char[]);

// displayContactHeader
// put function prototype here:
void displayContactHeader(void);

// displayContactFooter:
// put function prototype here:
void displayContactFooter(int);

// displayContact:
// put function prototype here:
void displayContact(const struct Contact*);

// displayContacts:
// put function prototype here:
void displayContacts(const struct Contact[], int);

// searchContacts:
// put function prototype here:
void searchContacts(const struct Contact[], int);

// addContact:
// put function prototype here:
void addContact(struct Contact[], int);

// updateContact:
// put function prototype here:
void updateContact(struct Contact[], int);

// deleteContact:
// put function prototype here:
void deleteContact(struct Contact[], int);
// sortContacts:
// put function prototype here:
void sortContacts(struct Contact[], int);