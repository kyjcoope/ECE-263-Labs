	/*
	Program Name: Lab 10
	Author's Name: Kyle Cooper
	Class, day, & time: ECE 263, Friday, 1:00pm-3:50pm
	ID: 0003304926

	Description: Program uses struct EmployeeData List[], this struct holds
	all the	information about employees the program will need. The program
	first prints a list of the employees that has not been sorted. The program
	then sorts this	List[].employeeID by increasing employeeID number, with the
	sortByID function, and then reprints the list. The program then computes
	the average salary of all	employees with the computeAverageSalary
	function and then prints it. The program then computes the number of
	employees over 40 with the GetNumberofEmployeeAgeOver40 function then
	prints the number.
	*/
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>

	#include "Lab10.h"

	//function prototypes
	int GetNumberofEmployeeAgeOver40(struct EmployeeData List[], int listsize);
	void sortByID(struct EmployeeData List[], int listsize); 
	double computeAverageSalary(struct EmployeeData List[],
		int listsize);

	int main()
	{

		//declarations
		struct EmployeeData List[25]={NULL};
		int seed=715;              
		int i,listsize;

		listsize= generate_list(List, seed);
	
		//prints original list
		printf("\noriginal list\n ***************\n");
		for(i=0;i< listsize; i++)
		printf("%24s %5d %7d %12.2lf\n",List[i].name, List[i].age,
			List[i].employeeID,	List[i].salary );
	
		//prints sorted list
		printf("\n\nsort by ID\n ***************\n");
		 sortByID(List, listsize);
		for(i=0;i< listsize; i++)
			printf("%24s %5d %7d %12.2lf\n",List[i].name, List[i].age,
				List[i].employeeID, List[i].salary );
	
		printf("\n\n");
    
		//prints avg salary
		printf("The average salary is %.2lf\n",
			computeAverageSalary(List, listsize));

		//prints number of employees over 40
		printf("The number of employee with age over 40 are %d\n",
			GetNumberofEmployeeAgeOver40(List, listsize));
	
		printf("\n\n");
	
	
	}
	//returns number of employees over 40
	int GetNumberofEmployeeAgeOver40(struct EmployeeData List[], int listsize)
	{
		int i, age = 0;
		for(i=0;i<listsize;i++)
		{
			if(List[i].age>40)
				age++;
		}
	return age;
	}
	//sorts list by increasing employeeID number
	void sortByID(struct EmployeeData List[], int listsize)
	{
	int i, j;
		int temp;
		for (i = 0; i < listsize - 1; i++)
		{
			for (j = 0; j < listsize - 1; j++)
			{
				if (List[j].employeeID > List[j + 1].employeeID)
				{
					temp = List[j].employeeID;
					List[j].employeeID = List[j + 1].employeeID;
					List[j + 1].employeeID = temp;
				}
			}
		}
	}
	//computes average salary of all employees
	double computeAverageSalary(struct EmployeeData List[], int listsize)
	{
		int i,num =0;
		double avg, sum = 0;
		for(i=0;i<listsize;i++)
		{
			sum += List[i].salary;
			num++;
		}
		avg=sum/(double)num;
		return avg;
	}