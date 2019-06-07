	/* 
	Program Name: Lab 2
	Author's Name: Kyle Cooper
	Class, day, & time: ECE 263, Friday, 1:00pm-3:50pm
	ID: 0003304926

	Description: Enter Harry and John's monthly salary, and family size.
	The program will then output their salary, number of family members,
	insurance expense, food expense, utility expense, and savings. Plus
	the totals for both.
	*/

	#define _CRT_SECURE_NO_WARNINGS
	#include <stdio.h>

	//Constants
	#define InsuranceRate 400.00
	#define FoodExpense 55.00
	#define UtilityExpese 0.25


	int main()

	{
	//Declarations for Harry
	int NumHarryFam;
	double HarrySalary;
	double HarryInsurance;
	double HarryFood;
	double HarryUtility;
	double HarrySavings;

	//Declarations for John
	int NumJohnFam;
	double JohnSalary;
	double JohnInsurance;
	double JohnFood;
	double JohnUtility;
	double JohnSavings;

	//Input For Harry
	printf("Enter Harry's monthly salary:");
	scanf("%lf", &HarrySalary);
	printf("Enter Harry's family size:");
	scanf("%d", &NumHarryFam);

	//Input for John
	printf("Enter John's monthly salary:");
	scanf("%lf", &JohnSalary);
	printf("Enter John's family size:");
	scanf("%d", &NumJohnFam);

	//Putting together Harrys info
	HarryInsurance = InsuranceRate*NumHarryFam;
	HarryFood = FoodExpense*NumHarryFam * 4;
	HarryUtility = (HarrySalary - InsuranceRate*NumHarryFam -
		FoodExpense*NumHarryFam * 4)*UtilityExpese;
	HarrySavings = HarrySalary - InsuranceRate*NumHarryFam -
		FoodExpense*NumHarryFam * 4 - UtilityExpese*(HarrySalary
		- InsuranceRate*NumHarryFam - FoodExpense*NumHarryFam * 4);

	//Putting together Johns info
	JohnInsurance = InsuranceRate*NumJohnFam;
	JohnFood = FoodExpense*NumJohnFam * 4;
	JohnUtility = (JohnSalary - InsuranceRate*NumJohnFam - FoodExpense*NumJohnFam
		* 4)*UtilityExpese;
	JohnSavings = JohnSalary - InsuranceRate*NumJohnFam - FoodExpense*NumJohnFam
		* 4 - UtilityExpese*(JohnSalary - InsuranceRate*NumJohnFam
		- FoodExpense*NumJohnFam * 4);


	//Title strings
	printf("\n\n%-9s%-15s%-11s%-14s%-9s%-12s%-s\n", "Name", "No. Family",
		"Salary", "Insurance", "Food", "Utility", "Savings");

	//Harry Totals
	printf("%-9s%-15d%-11.2lf%-14.2lf%-9.2lf%-12.2lf%-.2lf\n", "Harry",
		NumHarryFam,HarrySalary, HarryInsurance, HarryFood, HarryUtility,
		HarrySavings);

	//John Totals
	printf("%-9s%-15d%-11.2lf%-14.2lf%-9.2lf%-12.2lf%-.2lf\n", "John", NumJohnFam,
		JohnSalary, JohnInsurance, JohnFood, JohnUtility, JohnSavings);

	//Totals for Both
	printf("_______________________________________________________________\n\n");
	printf("%-9s%-15d%-11.2lf%-14.2lf%-9.2lf%-12.2lf%-.2lf\n\n", "Totals",
		NumHarryFam + NumJohnFam, HarrySalary + JohnSalary, HarryInsurance
		+ JohnInsurance, HarryFood + JohnFood, HarryUtility + JohnUtility,
		HarrySavings + JohnSavings);



   return 0;

	}