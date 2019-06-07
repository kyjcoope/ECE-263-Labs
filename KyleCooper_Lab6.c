	/*
	Program Name: Lab 6
	Author's Name: Kyle Cooper
	Class, day, & time: ECE 263, Friday, 1:00pm-3:50pm
	ID: 0003304926

	Description:  Program asks for user to enter an integer from 1-999.
	The program will exit when a non-integer is entered. The program will
	repeat if anything other than an ineteger from 1-999 is entered, but
	will not include that number in the output. When a non-integer is entered
	the program will output, the number of odd integers, the number of 
	even integers, the number of  one digit integers, the number of two 
	 integers, the number of three digit integers, the total number
	of integers inputted, and the average of all the integers inputted.
	*/
	#define _CRT_SECURE_NO_WARNINGS
	#include <stdio.h>

	//fuctions used
	int isMyODD(int);
	int isMyEVEN(int);
	int isMyONEDigit (int);
	int isMyTWODigit (int);
	int isMyTHREEDigit (int);
	double AverageNumber (double, double);
	int isNumChar (char);

	int main()
	{

	//declarations
	int numODD=0;
	int numEVEN=0;
	int numONEDigit=0;
	int numTWODigit=0;
	int numTHREEDigit=0;
	int TotalNumber=0;
	int sum = 0;
	double average = 0;
	int num, status;
 
	//Integer input
	printf("Enter an integer from 1 - 999(enter a non-integer to exit): ");
	while (scanf("%d",&num))
	{
	//calculations for integer input
	if(isMyODD(num)==1)
		numODD++;
	else if (isMyEVEN(num)==1)
		numEVEN++;
	if (isMyONEDigit(num)==1)
		numONEDigit++;
	else if(isMyTWODigit(num)==1)
		numTWODigit++;
	else if (isMyTHREEDigit(num)==1)
		numTHREEDigit++;

	sum++;
	TotalNumber = TotalNumber + num;
	}
	average = AverageNumber (sum, TotalNumber);

	//information about integer input
	printf("\nNumber of odd integers is: %d\n\n",numODD);
	printf("Number of even integers is: %d\n\n",numEVEN);
	printf("Number of one digit Integers is: %d\n\n",numONEDigit);
	printf("Number of two digit Integers is: %d\n\n",numTWODigit);
	printf("Number of three digit Integers is: %d\n\n",numTHREEDigit);
	printf("Total number of integers entered is: %d\n\n",TotalNumber);
	printf("The average of these integers is: %lf\n\n",average);

	return 0;
	}

	//fuctions used in program
	int isMyODD(int n)
	{
	if(n%2==1)
		return 1;
	else 
		return 0;
	}
	int isMyEVEN(int n)
	{
	if(n%2==0)
		return 1;
	else 
		return 0;
	}
	int isMyONEDigit (int  n)
	{
	if(n>=0&&n<10)
		return 1;
	else
		return 0;
	}
	int isMyTWODigit (int  n)
	{
	if (n>=10&&n<100)
		return 1;
	else
		return 0;
	}
	int isMyTHREEDigit (int  n)
	{
	if (n>=100&&n<1000)
		return 1;
	else return 0;
	}
	double AverageNumber (double n, double m)
	{
	double avg;
	avg = m/n;
	return avg;
	}

