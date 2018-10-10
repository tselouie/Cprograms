// Name:Louie Tse
// Student Number:027168103
// Email:lttse@myseneca.ca
// Section:SUU
// Workshop:4

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

const int min = 3, max = 10;
int high[5], low[5],
	numDays, i, highestTempDay, lowestTempDay, avgday,
	highestTemp = 0, lowestTemp = 99,  numAvgDay = 1;
float avgT, highSum = 0, lowSum = 0;

// Assigning Arrays Workshop

int main()
{
	printf("---=== IPC Temperature Calculator V2.0 ===---\n");

	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &numDays);
	printf("\n");

	//enter # of days inbetween 3 and 10
	while (numDays < min || numDays > max) {
		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &numDays);
	}
	//Enter temperatures while assigning to arrays
	for (i = 0; i < numDays; i++) {
		printf("Day %d - High: ", i + 1);
		scanf("%d", &high[i]);
		printf("Day %d - Low: ", i + 1);
		scanf("%d", &low[i]);
	}
	//Column Headers
	printf("\nDay  Hi  Low\n");
	//print arrays
	for (i = 0; i < numDays; i++) {
		printf("%d    %d    %d\n", i + 1, high[i], low[i]);
	}

	for (i = 0; i < numDays; i++) {
		if (high[i] >= highestTemp) {
			highestTemp = high[i];
			highestTempDay = i + 1;
		}
		if (low[i] <= lowestTemp) {
			lowestTemp = low[i];
			lowestTempDay = i + 1;
		}
	}
	printf("\nThe highest temperature was %d, on day %d\n", highestTemp, highestTempDay);
	printf("The lowest temperature was %d, on day %d\n", lowestTemp, lowestTempDay);

	//Loop to ask for number of days to calculate average temperature
	while (numAvgDay > 0) {
		printf("\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", numDays);
		scanf("%d", &numAvgDay);

		if (numAvgDay > 0) {
			while (numAvgDay < 1 || numAvgDay > numDays) {
				printf("\nInvalid entry, please enter a number between 1 and %d, inclusive: ", numDays);
				scanf("%d", &numAvgDay);
			}
	//Calculations for average day input
			for (i = 0; i < numAvgDay; i++) {
				highSum += high[i];
				lowSum += low[i];
			}
				avgT = (highSum + lowSum) / (numAvgDay * 2);
				printf("\nThe average temperature up to day %d is: %.2f\n", numAvgDay, avgT);
			
		}
	//Reset values
		highSum = 0;
		lowSum = 0;

	}
	printf("\nGoodbye!\n");
	return 0;
};
