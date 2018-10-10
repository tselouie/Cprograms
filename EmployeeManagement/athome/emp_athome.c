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
#include <string.h> //for memcpy
    // Define Number of Employees "SIZE" to be 2
#define SIZE 4

    // Declare Struct Employee
struct Employee {
    int empID;
    int age;
    double salary;
};

/* main program */
int main(void) {
    int i = 0;
    int empCounter = 0;
    int tempEmpCounter = 0;
    int option = 0;
    int empUpdate = 1;
    int deleteEmployee;
    double newSalary;
    printf("---=== EMPLOYEE DATA ===---\n\n");
    
        // Declare a struct Employee array "emp" with SIZE elements
        // and initialize all elements to zero
    
    struct Employee emp[SIZE] = { { 0 } };
    struct Employee tempEmp[SIZE] = { { 0 } };
    
    do {
            // Print the option list
        printf("1. Display Employee Information\n");
        printf("2. Add Employee\n");
        printf("3. Update Employee Salary\n");
        printf("4. Remove Employee\n");
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
                for (i = 0; i < empCounter; i++)
                    printf("%6d%9d%11.2lf\n", emp[i].empID, emp[i].age, emp[i].salary);
                printf("\n");
                
                break;
            case 2:	// Adding Employee
                
                printf("Adding Employee\n");
                printf("===============\n");
                if (empCounter >= SIZE) {
                    printf("ERROR!!! Maximum Number of Employees Reached\n\n");
                }
                else if (empCounter < SIZE) {
                    printf("Enter Employee ID: ");
                    scanf("%d", &emp[empCounter].empID);
                    printf("Enter Employee Age: ");
                    scanf("%d", &emp[empCounter].age);
                    printf("Enter Employee Salary: ");
                    scanf("%lf", &emp[empCounter].salary);
                    printf("\n");
                    empCounter++;
                };
                break;
                
            case 3: //Updating Employee
                
                printf("Update Employee Salary\n");
                printf("======================\n");
                do {
                    printf("Enter Employee ID: ");
                    scanf("%d", &empUpdate);
                    for (i = 0; i < empCounter; i++)
                        {
                        if (empUpdate == emp[i].empID) {
                            printf("The current salary is %6.2lf\n", emp[i].salary);
                            printf("Enter Employee New Salary: ");
                            scanf("%lf", &newSalary);
                            printf("\n");
                            emp[i].salary = newSalary;
                            break;
                        }
                        };
                } while (empUpdate != emp[i].empID);
                
                break;
                
            case 4: //Removing Employee
                printf("Remove Employee\n");
                printf("===============\n");
                
                do {
                    printf("Enter Employee ID: ");
                    scanf("%d", &deleteEmployee);
                    
                    for (i = 0; i < empCounter; i++) {
                        if (deleteEmployee == emp[i].empID) {
                            break;
                        }
                    }
                } while (deleteEmployee != emp[i].empID);
                
                for (i = 0; i < empCounter; i++) {
                    if (deleteEmployee != emp[i].empID) {
                        tempEmp[tempEmpCounter].empID = emp[i].empID;
                        tempEmp[tempEmpCounter].age = emp[i].age;
                        tempEmp[tempEmpCounter].salary = emp[i].salary;
                        tempEmpCounter++;
                    }
                }
                    //memcpy syntax(void*destination, const void * source, size_t num);
                    //copies the values of num bytes from the location pointed to by source directly to the memory block pointed to by destination
                memcpy(&emp, &tempEmp, sizeof(tempEmp));
                empCounter = tempEmpCounter;
                
                printf("Employee %d will be removed\n\n", deleteEmployee);
                
                break;
                
            default: //Displays error
                printf("ERROR: Incorrect Option: Try Again\n\n");
                break;
        }
    } while (option != 0);
    return 0;
};
