// binary.c
/* binary 			decimal			format
	   0			  0				0
	   1			  1				2^0
	  10			  2				2^1
	 100			  4				2^2
	1000			  8				2^3
	10^4			 16				2^4
	10^5			 32				2^5
	10^6			 64				2^6
	10^7			128				2^7

format:
*/
#include "stdio.h"
#include "math.h"
#include "stdlib.h"

// test the numerial digit of the target
/*divide the target by 10 recursively until less than 10 
increase the digit simultaneously in the recurrence
finally add up to the numerial digit*/
int numerial_digit(int target)
{
	int digit = 1;
	for(;;++digit)
	{
		if (abs(target) < 10)	return digit;
		target = target / 10;
	}
}

int binary_to_decimal(int target,int digit)
{
	int number = 0;
	int sum = 0;
	for (int i = 0; i < digit; ++i)
	{
		number = target % 10 * pow(2,i);
		target = target / 10;
		sum += number;
	}
	return sum;
}

int decimal_to_binary(int target)
{
	int number = 0,sum = 0;
	for (int i = 0;target != 0; ++i)
	{
		number = target % 2;
		target = target / 2;
		sum += number * pow(10,i);
	}
	return sum;
}

int input()
{	int digit = 0,target = 0;
	printf("Please input the target number\n");
	scanf("%d",&target);
	return target;
}

int test_binary(int target,int digit)
{
	for (int i = 0; i < digit; ++i)
	{
		if (target % 10 > 1)
		{
			printf("Input Error,It`s not binary number,Please input again!\n");			
			return 1;
		}
			target = target/10;
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	int target = 0;
	int choice = 0,digit = 0,flag = 1;

	printf("Please choose the converter(input 0 or 1):\n");
	printf("binary to decimal converter for 0.\n");
	printf("decimal to binary converter for 1.\n");
	scanf("%d",&choice);

	if (choice == 0)
	{	
		for(;flag == 1;)
		{
			target = input();
			digit = numerial_digit(target);
			flag = test_binary(target,digit);
		}
		digit = numerial_digit(target);
		target = binary_to_decimal(target,digit);
		printf("The decimal number is %d\n", target);
	}
	else
	{
		target = input();
		target = decimal_to_binary(target);
		printf("The binary number is %d\n",target);
	}

	return 0;
}