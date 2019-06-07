/*
Program Name: Lab 9
Author's Name: Kyle Cooper
Class, day, & time: ECE 263, Friday, 1:00pm-3:50pm
ID: 0003304926

Description: Program asked user to enter two strings, program then
checks if string 2 is a substring of string 1,and returns answer.
Program then checks if string 1 and 2 are palindromes, and returns
answer. Program will terminate if string 1 is a length of 1, or string
2 is has no length, or if string 2 is longer then string 1.
*/




	#define _CRT_SECURE_NO_WARNINGS
	#include <stdio.h>

	int computeLength(char *str);
	int isSubString(char *str1, char *str2);
	int isPalindrome(char *str);

	int main()
	{
	char str1[200];
	char str2[200];
	int length1, length2, sub, palin1, palin2, flag;
	printf("Enter String 1: ");
	gets(str1);
	printf("Enter String 2: ");
	gets(str2);

	length1 = computeLength(str1);
	length2 = computeLength(str2);

	if (length1 == 1)
		flag = 1;
	else if (length2 == 0)
		flag = 1;
	else if (length2 > length1)
		flag = 1;
	else
		flag = 0;

	if (flag == 0)
	{
		sub = isSubString(str1, str2);

		if (sub == 1)
			printf("String 2 is a substring of String 1.\n");
		else
			printf("String 2 is not a substring of String 1.\n");

		palin1 = isPalindrome(str1);
		palin2 = isPalindrome(str2);

		if (palin1 == 1)
			printf("%s is a Palindrome\n", str1);
		else
			printf("%s is not a Palindrome.\n", str1);

		if (palin2 == 1)
			printf("%s is a Palindrome\n", str2);
		else
			printf("%s is not a Palindrome.\n", str2);
	}
	else
	{
		printf("Program terminated.\n");
		return 0;
	}

	return 0;
	}		
	int computeLength(char *str)
	{
	int size = 0;

	while (*str != '\0')
	{
		size++;
		str++;
	}

	return size;
	}
	int isSubString(char *str1, char *str2)
	{
	int subsize = 0, len;
	len = computeLength(str2);
	while (*str1 != '\0')
	{
		if (*str1 == *str2)
		{
			subsize++;
			str2++;
		}
		str1++;

	}
	if (subsize == len)
		return 1;
	else
		return 0;
	}
	int isPalindrome(char *str)
	{
	int i = 0, size = 0, size2 = 0, len;
	char str1[200];

	len = computeLength(str);

	while (*str != '\0')
	{
		len--;
		str1[len] = *str;
		str++;
		size++;
	}
	str -= size;

	while (*str == str1[i] && *str != '\0')
	{
		str++;
		i++;
		size2++;
	}

	if (size == size2)
		return 1;
	else
		return 0;
	}