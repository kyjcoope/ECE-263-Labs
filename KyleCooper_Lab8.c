/*
Program Name: Lab 8
Author's Name: Kyle Cooper
Class, day, & time: ECE 263, Friday, 1:00pm-3:50pm
ID: 0003304926

Description: Program asks user to input a non-zero decimel number.
The program will keep reading user input until 0 or a float number
is entered. Input is stored in a double array List[50]. Program will
print the inverse sum of the array List, using the myInvSum function.
After this the program will print all the numbers in the array in
rows of 4, using the myPrint function. The program will then sort the
numbers in the array in increasing order using the Sort function,
then print it using the myPrint fuction. The program will then sort
the array based on the hundredths digit in increasing order, and
print it using the myPrint function again. Program will then do 
one last inverse sum print.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//function prototypes
int readDouble(double x[]);
void myPrint(double x[], int size);
double myInvSum(int x[], int size);
void Sort(double x[], int size);
void specialSort(double x[], int size);

int main()
{
	//declarations for main
	int size;
	double List[50];

	//Function calls and printf statements
	size = readDouble(List);
	printf("Inverted sum is %lf\n\n", myInvSum(List, size));
	printf("Input values:\n");
	myPrint(List, size);
	Sort(List, size);
	printf("Input values sorted by increasing value:\n");
	myPrint(List, size);
	printf("Input values sorted by increasing hundredths digit:\n");
	specialSort(List, size);
	myPrint(List, size);
	printf("Inverted sum is %lf\n\n", myInvSum(List, size));
	return 0;
}
//User input
int readDouble(double x[])
{
	double num;
	int size = 0, flag = 1;
	while (flag == 1)
	{
			if (size >= 50)
				break;
			printf("Please enter number: ");
			if (scanf("%lf", &num) != 1)
			{
				break;
			}
			else if (num == 0)
				flag = 0;
			else
			{
				x[size] = num;
				size++;
			}
	}
	return size;
}
//Inverse sum function
double myInvSum(double x[], int size)
{
	int i;
	double sum = 0;
	for (i = 0; i < size; i++)
	{
		sum = sum + 1/x[i];
	}
	printf("\n");
	return sum;
}
//Print function that prints in rows of 4
void myPrint(double x[], int size)
{
	int row,col,i=0;
	for (row = 0; row <= size / 4 + 1; row++)
	{
		if (i >= size)
			break;
		for (col = 0; col <= 3; col++)
		{
			if (i >= size)
				break;
			printf("%lf\t", x[i]);
			i++;
		}
		printf("\n");
	}
	printf("\n");
}
//Sort function that sorts array in increasing order
void Sort(double x[], int size)
{
	int i, j;
	double temp;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (x[j] > x[j + 1])
			{
				temp = x[j];
				x[j] = x[j + 1];
				x[j + 1] = temp;
			}
		}
	}
}
//specialSort fuction that sorts array by increasing hundredths digit
void specialSort(double x[], int size)
{
	int i, j;
	double temp,num1,num2;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			num1 = x[j] * 100;
			num2 = x[j + 1] * 100;

			if ((int)num1%10 > (int)num2%10)
			{
				temp = x[j];
				x[j] = x[j + 1];
				x[j + 1] = temp;
			}
		}
	}
}
