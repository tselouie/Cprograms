/*
Name:Louie	Tse
Student number:027168103
Email:lttse@myseneca.ca
Workshop:5
Section:SUU
Date:October 11,2017
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Define Number of Employees "SIZE" to be 2
#define SIZE 2		

// Declare Struct Employee 
struct Employee {
	int empID;
	int age;
	double salary;
};

/* main program */
int main(void) {
	int i = 0;
	int option = 0;
	int validEmployee = 0;
	printf("---=== EMPLOYEE DATA ===---\n\n");

	// Declare a struct Employee array "emp" with SIZE elements 
	// and initialize all elements to zero

	struct Employee emp[SIZE] = { 0 };

	do {
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");

		// Capture input to option variable
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:
			printf("Exiting Employee Data Program. Good Bye!!!\n");
			// Exit the program

			break;
		case 1: // Display Employee Data

			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");
			for (int counter = 0; counter < i; counter++)
				printf("%6d%9d%11.2lf\n", emp[counter].empID, emp[counter].age, emp[counter].salary);
			printf("\n");

			break;
		case 2:	// Adding Employee
			
				printf("Adding Employee\n");
				printf("===============\n");
				if (validEmployee >= SIZE) {
					printf("ERROR!!! Maximum Number of Employees Reached\n\n");
				}
				else if (i < SIZE) {
				printf("Enter Employee ID: ");
				scanf("%d", &emp[i].empID);
				printf("Enter Employee Age: ");
				scanf("%d", &emp[i].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[i].salary);
				printf("\n");
				i++;
				validEmployee = i;
			};

			break;
		default: //Displays error
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);

	return 0;
}



//PROGRAM OUTPUT IS SHOW BELOW

/*
---=== EMPLOYEE DATA ===---

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 111
Enter Employee Age: 34
Enter Employee Salary: 78980.88

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 112
Enter Employee Age: 41
Enter Employee Salary: 65000

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
ERROR!!! Maximum Number of Employees Reached

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
111       34   78980.88
112       41   65000.00

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 0

Exiting Employee Data Program. Good Bye!!!

*/
