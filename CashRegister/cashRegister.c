
/*
Name:      <Louie Tse>
	Student# : <027168103>
	Section : <SUU>
	email: lttse@myseneca.ca
* /

	// Start your code below:
*/
#include <stdio.h>
#include <math.h>
	int main(void)
{
	//Variable Declarations
	double num, balOwing, quartBal, dimeBal, nickBal;
	float GST, pennyBal;
	int loonReq, quartReq, dimeReq, nickReq, pennyReq;
	int quarter = 25, dime = 10, nick = 5, penny = 1;
	

	//Request user input amount

	printf("Please enter the amount to be paid: $");
	scanf("%lf", &num);

	//Tax & Balance

	GST = num * .13 +.005;
	printf("GST: %.2f\n", GST);

	balOwing = num + GST;
	printf("Balance owing: $%.2lf\n", balOwing);

	//Calculating division modulus

	loonReq = balOwing;
	balOwing -= loonReq;
	printf("Loonies required: %d, balance owing $%.2lf\n", loonReq,balOwing);

	quartReq = balOwing * 100 / quarter;
	quartReq = (int)quartReq;
	balOwing = balOwing * 100;
	quartBal = (int)balOwing % (quartReq * quarter);
	printf("Quarters required: %d, balance owing $%.2lf\n",quartReq,quartBal/100);

	dimeReq = quartBal / dime;
	dimeBal = quartBal * 100;
	dimeBal = (int)quartBal - (dime * dimeReq);
	printf("Dimes required: %d, balance owing $%.2lf\n", dimeReq, dimeBal/100);

	nickReq = dimeBal / nick;
	nickBal = dimeBal * 100;
	nickBal = (int)dimeBal % nick;
	printf("Nickels required: %d, balance owing $%.2lf\n", nickReq, nickBal/100);

	pennyReq = nickBal* 100 / penny;
	pennyBal = nickBal * 100;
	pennyBal = (int)pennyBal % penny;
	printf("Pennies required: %d, balance owing $%.2lf\n", pennyReq/100, pennyBal / 100);

	return 0;
}
