	/*
	Program Name: Lab 3
	Author's Name: Kyle Cooper
	Class, day, & time: ECE 263, Friday, 1:00pm-3:50pm
	ID: 0003304926

	Description: There are 4 parts to this program.
	
	Part 1 will ask you to enter a value for x. The program will then give you
	two values for ln(x); a true value and an approximation of that value.
	Then the program will give you the approximate error between these two
	values.

	Part 2 asks you to enter a value for wRad in radians then converts that
	value to degrees. The program then outputs the value of wRad in degrees.
	The program will then ask you to enter a value for xDeg in degrees
	then converts that value to radians. The program then outputs the value
	of xDeg in radians.

	Part 3 takes the value for xRad entered in part 2 and uses the function
	cos(xRad) and our own approximation of cos using Cx to find the value of
	the angle xRad in radians. The program then outputs cos(xRad) and our
	approximation of xRad using Cx and the amount of error between the two.

	Part 4 asks you to enter a value for A, then computes cos(3A) and our
	approximation C(3A), then outputs the true value for cos(3A) and our
	approximation for C(3A), plus the error between cos(3A) and C(3A).

	*/



	#define _CRT_SECURE_NO_WARNINGS
	#include <stdio.h>
	#include <math.h>

	//constants
	#define Deg 57.295770
	#define Rad 0.017453333


	int main()





	{
	
	//declarations
	double trueValue;
	double approxValue;
	double approxError;
	double x;
	double wRad;
	double xDeg;
	double wDeg; 
	double xRad; 
	double cosx;
	double Cx;
	double errorCos;
	double A;
	double cos3A;
	double C3A;
	double errorCos3A;

	//Part 1

	//x value for part 1
	printf("Please enter a number x < 1: ");
	scanf("%lf", &x);

	//Calculations for part 1
	trueValue = log(1+x);
	approxValue = x - (pow(x,2) / 2) + (pow(x,3) / 3) - (pow(x,4) / 4);
	approxError = fabs(trueValue - approxValue);

	//output for part 1
	printf("\nThe true vaule of ln(1 + %lf) is: %lf\n", x, trueValue);
	printf("The our approximation for L(%lf) is: %lf\n", x, approxValue);
	printf("The amount of error in this approximation is: %lf\n\n", x,
		approxError);


	
	
	//part 2
	

	//wRad value for part 2
	printf("Enter a value in Radians: ");
	scanf("%lf", &wRad);

	//Calculations for part 2
	wDeg = wRad*Deg;
	
	//xDeg value for part 2
	printf("\nThe vaule of %lf in radians is %lf in degrees.\n\n", wRad, wDeg);
	printf("Enter an angle in Degrees: ");
	scanf("%lf", &xDeg);

	//Calculations for part 2
	xRad = xDeg*Rad;

	//xRad value for part 2
	printf("\nThe vaule of %lf Degrees is %lf Radians.\n\n", xDeg, xRad);
	

	//part 3
	
	//Calculations for Cos(xRad) and C(x)
	cosx = cos(xRad);
	Cx = 1 - (pow(xRad,2) / 2) + (pow(xRad,4) / 24) - (pow(xRad,6) / 720);
	errorCos = fabs(cosx - Cx);

	//Output for Cos(xRad) and C(x)
	printf("The value for Cos(%lf) is: %lf\n", xRad, cosx);
	printf("The our approximation for C(%lf) is: %lf\n", xRad, Cx);
	printf("The amount of error in this approximation is: %lf\n\n", errorCos);
	
	
	//part 4
	
	//Enter value for A
	printf("Enter a vaule A for cos(3A): ");
	scanf("%lf",&A);

	//Calculation value for cos(3A) and C(3A)
	cos3A = cos(3*A);
	C3A = 1 - pow(3*A,2) / 2 + pow(3*A,4) / 24 - pow(3*A,6) / 720;
	errorCos3A = fabs(cos3A - C3A);

	//Output for cos(3A) and C(3A)
	printf("\nThe vaule for cos(3 * %lf) is: %lf\n",A, cos3A);
	printf("The our approximation for C(3 * %lf) is: %lf\n",A, C3A);
	printf("The amount of error in this approximation is: %lf\n\n",
		errorCos3A);

	
	return 0;

	}