/*
Program Name: Lab 12
Author's Name: Kyle Cooper
Class, day, & time: ECE 263, Friday, 1:00pm-3:50pm
ID: 0003304926

Description: Program copys text from File.pdf, and creates file
New.txt and pastes text. Program then prints the number of bytes in
both File.pdf and New.pdf(they should be the same). Program then
opens Michael.txt and copies text to a new file named New_Michael.txt
and changes everything to uppercase. Program then opens new
Encrypt_Michael.txt and copies text from Michael.txt, encrypts that 
text then pastes that text into the new file Encrypt_Michael.txt.
Program then opens a new file named Decrypt_Michael.txt and then
copies text from Encrypt_Michael.txt and then decrypts that text,
then pastes it into Decrypt_Michael.txt.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stddef.h>

int main(void)
{
	FILE *fp1, *fp2;
	char c, a, b;
	int i;
	int counter = 0;

	if ((fp1 = fopen("File.pdf", "rb")) == NULL)
	{
		fclose(fp1);
	}

	if ((fp2 = fopen("New.pdf", "wb")) == NULL)
	{
		fclose(fp2);
	}

	while ((i = fgetc(fp1)) != EOF)
	{
		fputc(i, fp2);
	}

	fseek(fp1, 0, SEEK_END);
	fseek(fp2, 0, SEEK_END);

	printf("\nNumber of bytes in fp1: %d\n", ftell(fp1));
	printf("\nNumber of bytes in fp2: %d\n\n", ftell(fp2));
	
	fclose(fp1);
	fclose(fp2);
	
	if ((fp1 = fopen("Michael.txt", "r")) == NULL)
	{
		fclose(fp1);
	}

	if ((fp2 = fopen("New_Michael.txt", "w")) == NULL)
	{
		fclose(fp2);
	}
	
	while ((c = fgetc(fp1)) != EOF)
	{
		if (c >= 'a'&&c <= 'z')
			c = c - 32;
		fputc(c, fp2);
	}
	
	fclose(fp2);

	if ((fp2 = fopen("Encrypt_Michael.txt", "w+")) == NULL)
	{
		fclose(fp2);
	}

	fseek(fp1,0,SEEK_SET);

	while ((c = fgetc(fp1)) != EOF)
	{
		if(counter!=0)
		{
			a=fgetc(fp2);
			c=c^a;
		}
		counter++;
		fputc(c, fp2);
	}

	fclose(fp1);
	fclose(fp2);
	
	if ((fp1 = fopen("Encrypt_Michael.txt", "r")) == NULL)
	{
		fclose(fp1);
	}

	if ((fp2 = fopen("Decrypt_Michael.txt", "w")) == NULL)
	{
		fclose(fp1);
	}

	counter = 0;

	while ((c = fgetc(fp1)) != EOF)
	{
		
		if(counter!=0)
		{
			a = fgetc(fp1);
			c=c^a;
		}
		counter++;
		fputc(c, fp2);
		
	}
	
	fclose(fp1);
	fclose(fp2);
	
	return 0;
}

