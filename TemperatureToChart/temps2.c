// Name:Louie Tse	
// Student Number:027168103
// Email:lttse@myseneca.ca
// Section:SUU
// Workshop:4

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

const int min = 3, max = 10, n = 4;
int numDays, high[5], low[5], i;

// Assigning Arrays Workshop

int main()
{

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");

		printf("Please enter the number of days, between 3 and 10, inclusive: ");
		scanf("%d", &numDays);

//enter # of days inbetween 3 and 10
		while (numDays < min || numDays > max) {

			printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
			scanf("%d", &numDays);
		}
			printf("\n");
//Enter temperatures while assigning to arrays
		for (i = 0; i < n; i++){
			printf("Day %d - High: ", i + 1);
			scanf("%d", &high[i]);
			printf("Day %d - Low: ", i + 1);
			scanf("%d", &low[i]);
								}
//Column Headers
			printf("Day Hi Low\n");
//print arrays
		for (i = 0; i < n; i++){
			printf("%d   %d   %d\n", i, high[i], low[i]);
		}
	return 0;
};


