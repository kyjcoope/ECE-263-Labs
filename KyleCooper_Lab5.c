	/*
	Program Name: Lab 5
	Author's Name: Kyle Cooper
	Class, day, & time: ECE 263, Friday, 1:00pm-3:50pm
	ID: 0003304926

	Description: Program goes into a do loop then takes input for taxable
	income.	Program then goes into another do loop and takes a character
	input for the tax code. If the tax code character is not a valid
	character, the program will reprint the tax code information and
	ask for the tax code again. Once a valid character is entered, the
	program will exit the loop and then calculate the amount of tax owed
	based on the entered taxable income and entered tax code. Program
	will then ask for the user to enter a new taxable income. This process
	will repeat until 'Q' is entered as a tax code entry. When this is done
	Program will exit both do loops and calculate the total amount of
	income and calculated tax.
	*/

	#define _CRT_SECURE_NO_WARNINGS
	#include <stdio.h>

	int main()
	{

	//Declarations
	double income, num1 = 0, num2 = 0, tax = 0, taxTotal = 0, incomeTotal = 0;
	char ch;

	//First do loop
	do
	{
		printf("Please enter your taxable income for this year: $");
		scanf("%lf", &income);

		//Do loop for tax code
		do
		{
			//Tax code info
			printf("\n%-30sTax\n\n", "Category");
			printf("%-30s15%% of first $17,850 plus 28%% of excess\n\n",
				"S - Single");
			printf("%-30s15%% of first $23,900 plus 28%% of excess\n\n",
				"H - Head of Household");
			printf("%-30s15%% of first $29,750 plus 28%% of excess\n\n",
				"J - Married, Joint");
			printf("%-30s15%% of first $14,875 plus 28%% of excess\n\n",
				"D - Married, Divorced");
			printf("Enter 'Q' to quit and view totals.\n\n");
			printf("Please enter a valid Tax code: ");

			//Tax code input
			scanf(" %c", &ch);

		} while (ch!='D'&&ch != 'H'&&ch != 'J'&&ch != 'S'&&ch!='Q');
		printf("\n");
		/*If statement that calculates income tax based on income and
		tax code input.*/
		if (ch == 'S')
		{
			if (income > 17850)
			{
				num1 = (income - 17850)*.28;
				num2 = 2677.5;
				tax = num1 + num2;
			}
			else if (income <= 17850)
				tax = income * .15;
		}
		else if (ch == 'H')
		{
			if (income > 23900)
			{
				num1 = (income - 23900)*.28;
				num2 = 3585;
				tax = num1 + num2;
			}
			else if (income <= 23900)
				tax = income * .15;
		}
		else if (ch == 'J')
		{
			if (income > 29750)
			{
				num1 = (income - 29750)*.28;
				num2 = 4462.5;
				tax = num1 + num2;
			}
			else if (income <= 29750)
				tax = income * .15;
		}
		else if (ch == 'D')
		{
			if (income > 14875)
			{
				num1 = (income - 14875)*.28;
				num2 = 2231.25;
				tax = num1 + num2;
			}
			else if (income <= 14875)
				tax = income * .15;
		}
		else if (ch == 'Q')
		{
			income = 0;
			tax = 0;
		}

		//Calaculates income and tax total for output
		
		incomeTotal = incomeTotal + income;
		taxTotal = taxTotal + tax;

	} while (ch != 'Q');

	//Output for total income and tax total
	printf("Total income entered equals: $%.2lf\n\n",incomeTotal);
	printf("Total taxes owned equals: $%.2lf\n\n", taxTotal);

	return 0;
	}