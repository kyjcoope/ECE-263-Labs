	/*
	Program Name: Lab 4
	Author's Name: Kyle Cooper
	Class, day, & time: ECE 263, Friday, 1:00pm-3:50pm
	ID: 0003304926

	Description: Part 1, program asks you to enter an odd number for diamond
	height. Program then converts height into a number(num) which is used
	as the limit in the "for" loop for both the top and bottom halfs of the
	diamond. This number(num) is also used when calculating the proper number
	of spaces in the top half of the diamon and the proper number of stars in
	the bottom half of the diamond.
	Note: You can enter an even number, but the height will be 1 less then
	your desired height.

	Part 2, program asks you to enter a size for your multiplication table.
	Program then uses the number you entered for size as the limit in the 
	"for" loops for this program. This allows the loops to produce the
	correct	number of rows and columns for the multiplicating table.
	*/





	#define _CRT_SECURE_NO_WARNINGS
	#include <stdio.h>

	void printstars(int);
	void printspace(int);


	int main()

	{
	//Declarations for part 1
	int height;
	int num;
	int top;
	int bot;
	int a = 1;
	int b = 1;
	int c = 1;
	int d = 1;
	int space;
	int stars;

	//Declarations for part 2
	int size;
	int row;
	int col;
	int x;
	int y;
	int multiplier = 0;

	//Part 1

	//Input for diamond height
	printf("Enter the Height of your Diamond(must be odd number): ");
	scanf("%d", &height);
	printf("\n");

	//Calculation used for number of spaces(top) and stars(bot)
	num = (height + 1) / 2;
	
	//Creating top half of diamond
	for (top = 1; top <= num; top++)
		{
			space = num - a++;
			stars = b++;
			printspace(space);
			printstars(stars);
			printf("\n");
		}
		
	//Creating bottom half of diamond
	for (bot = 1; bot <= num; bot++)
		{
			space = c++;
			stars = num - d++;
			printspace(space);
			printstars(stars);
			printf("\n");
		}

	//Part 2

	//Input for multiplication table size
	printf("Enter size of your multiplication table: ");
	scanf("%d", &size);
	printf("\n");

	//Creating multiplication table
	for (row = 1; row <= size; row++)
	{
		x = 1;
		multiplier++;
		for (col = 1; col <= size; col++)
		{
			y = x++ * multiplier;
			printf("%-4.d", y);
		}
		printf("\n");
		printf("\n");
	}
	printf("\n");

	return 0;
	}


	//Print fuction used in part 1 for number stars
	void printstars(int numberstars)
	{
		int i;

		for (i = 0; i<numberstars; i++)
		{
			printf("* ");
		}
	}

	//Print fuction used in part 1 for number space
	void printspace(int numberspace)
	{
		int j;

		for (j = 0; j<numberspace; j++)
		{
			printf(" ");
		}
	}

