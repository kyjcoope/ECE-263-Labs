/*
Program Name: Lab 7
Author's Name: Kyle Cooper
Class, day, & time: ECE 263, Friday, 1:00pm-3:50pm
ID: 0003304926

Description:  Program asks user to input values from 0-99. Values entered,
will be input into an array that was passed to the readData function. The
readData function will keep track of the number of integers input into the
array, and return this value. After this the program will use another
function SumDigits, to output the sum of the ones and tens columns for
the array aR[]. Next the program will use the function Average to
calulate the average of all integers input into array aR[], the
function will then return this average. Program will then output
the value of average.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//function prototypes
int readData(int  aR[], int maxSize);
void SumsDigit(int aR[], int size);
double Average(int aR[], int size);

int main()
{
	//declarations for main
	double avg;
	int size = 0, maxSize = 100;
	int aR[100];
	

	//information about what program does
	printf("Enter integers from 0-99, to stop enter a non-integer or");
	printf("a value > 100,\nnegative values will be ignored.\n\n");
	
	//function puts scanf input into aR[] then returns size
	//(which is the number of valid integers entered)
	size = readData(aR, maxSize);

	printf("\n");

	//Function printf the totals for the
	//ones and tens of integers input into aR[]
	SumsDigit(aR,size);

	//Function returns the average of all integers input into aR[]
	avg = Average(aR, size);

	//Prints the average returned by the previous function
	printf("The average of all valid integers entered is: %lf\n\n", avg);

	return 0;
}

int readData(int aR[], int maxSize)
{
	//declarations for readData
	int num, size = 0, flag = 1;

	//while statment controlled by flag
	while (flag == 1)
	{
		//Makes sure you dont assign more integers then can be assigned
		if (size>=maxSize)
			break;
		
		{
		//user input for aR[], if its not an integer the loop will break,
		//input will not be entered into aR[]
		printf("Please enter number: ");
		if (scanf("%d", &num) != 1)
		{
			break;
		}
		//If num >= 100 flag will be set to 0 and the loop will stop,
		//input will not be entered into aR[]
		else if (num >= 100)
			flag = 0;
		//If num is negative the input will not be entered into aR[],
		//but the loop will not stop.
		else if (num < 0)
			continue;
		//If entered input is between 0 and 99 it will be input into aR[]
		else	
			{
			aR[size] = num;
			//Size keeps track of the number of integers input into aR[]
			size++;
			}
		}
	}
	return size;
	}

void SumsDigit(int aR[], int size)
{
	//declarations for SumsDigit
	int tens = 0,i,one,ones = 0;

	for (i = 0; i <= size; i++)
	{	//calculation for ones
		one = aR[i]%10;
		if (aR[i] >= 10)
		{
			//calculation and sum for tens
			tens += (aR[i] - one) / 10;
		}
		//sum of ones
		ones += one;
	}
	//outputs tens and ones totals
	printf("Sum of tens column = %d\nSum of ones column %d\n\n", tens, ones);
}

double Average(int aR[], int size)
{
	//declarations for Average
	int i, sum = 0;
	double avg;

	//loop that calculates average of integers input into aR[]
	for (i = 0; i < size; i++)
	{
		sum += aR[i];
	}
	avg = sum / (double)size;

	return avg;
}
