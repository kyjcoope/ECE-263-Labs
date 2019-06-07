/*
Program Name: Lab 11
Author's Name: Kyle Cooper
Class, day, & time: ECE 263, Friday, 1:00pm-3:50pm
ID: 0003304926
Description: Program creates a link list of with a number
of nodes equal to an integer number entered by the user.
The nodes are then filled with information using the provided
assigndata fuction. The program then sorts the link list by in decreasing
order using the sort function, after that the program then uses the
function AvgStrlen which returns the avg strlen of EmployeeData.name
for all nodes.
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Lab11.h"
double AvgStrlen(struct EmployeeData *);
struct EmployeeData * createNode(struct EmployeeData *head);
void AddNode(struct EmployeeData *head, int num);
void sort(struct EmployeeData *head, int num);
void main()
{
	int i, num;
	struct EmployeeData *head;
	struct EmployeeData *walker;
	head = (struct EmployeeData *) malloc(sizeof(struct EmployeeData));
	head->nextEmployee = NULL;
	assigndata(head);
	printf("Enter Integer: ");
	scanf("%d", &num);
	for (i = 1; i<num; i++)
	{
		head = createNode(head);
	}
	walker = head;
	printf("%-20s%-20s%-20s\n", "Name", "ID", "Wage");
	while (walker!=NULL)
	{
		printf("%-20s", walker->name);
		printf("%-20d", walker->ID);
		printf("%-20lf\n", walker->wage);
		walker = walker->nextEmployee;
	}
	walker = head;
	printf("\n\n");
	printf("\nThe Average strlen of link-list is: %lf\n\n", AvgStrlen(head));
}
double AvgStrlen(struct EmployeeData *head)
{
	int i, counter = 0;
	double avg, sum = 0;
	struct EmployeeData* walker = head;
	while (walker->nextEmployee != NULL)
	{
		i = strlen(walker->name);
		sum += i;
		walker = walker->nextEmployee;
		counter++;
	}
	avg = sum / (double)counter;
	return avg;
}
struct EmployeeData * createNode(struct EmployeeData *head)
{
	int i = 0,j;
	struct EmployeeData* newNode;
	struct EmployeeData* walker=head;
	newNode = (struct EmployeeData *) malloc(sizeof(struct EmployeeData));
	if (newNode == NULL)
	{
		printf("Error\n");
		exit(1);
	}
	assigndata(newNode);
	newNode->nextEmployee = NULL;
	if (newNode->wage < head->wage)
	{
		newNode->nextEmployee = head;
		head = newNode;
	}
	else if (newNode->wage > head->wage)
	{
		walker = head;
		while (newNode->wage > walker->wage&&walker->nextEmployee != NULL)
		{
			walker = walker->nextEmployee;
			i++;
		}
		if (newNode->wage > walker->wage)
		{
			walker->nextEmployee = newNode;
		}
		else if(newNode->wage <= walker->wage)
		{
			walker = head;
			for (j = 0; j < i - 1; j++)
			{
				walker = walker->nextEmployee;
			}
			newNode->nextEmployee = walker->nextEmployee;
			walker->nextEmployee = newNode;
		}
	}
	return head;
}