// Name:Louie Tse		
// Student Number:027168103
// Email:lttse@myseneca.ca	
// Section:SUU
// Workshop:Workshop 3


#define NUMS 3
#include <stdio.h>

int main()

{
	int high, low, day; 
	int totalHigh = 0, totalLow = 0;
	float avg, sum;
	float totalDays = 0;

//Title text
	printf("---=== IPC Temperature Analyzer ===---\n");

//Loop for changing day
	for (day = 1; day <= NUMS; day++)
	{
		
		printf("Enter the high value for day %d: ", day);
		scanf("%d", &high);
		printf("\n");
		printf("Enter the low value for day %d: ", day);
		scanf("%d", &low);
		printf("\n");

//Error conditions to print notice and repeat day
	while (high > 40 || low < -40 || low > high)
	{
		printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
		printf("\n");
		printf("Enter the high value for day %d: ", day);
		scanf("%d", &high);
		printf("\n");
		printf("Enter the low value for day %d: ", day);
		scanf("%d", &low);
		printf("\n");

	}
//Counting inputs
	if (high < 41 && low > -41)
	{
			totalDays+=2;
	}

			totalHigh += high;
			totalLow += low;
		}
//print the average after loop is complete	
			sum = totalHigh + totalLow;
			avg = sum / totalDays;

		printf("The average (mean) temperature was: %.2f\n", 
avg);

	return 0;
}
		
			
		
		
