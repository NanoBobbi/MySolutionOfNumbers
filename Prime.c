// Prime.c
#include "stdio.h"
#include "math.h"
#include "stdlib.h"

int main(int argc, char const *argv[])
{
	long target = 2;
	long j = 2;

	printf("Please input the target number to factorize!\n");
	scanf("%ld",&target);

	printf("The prime numbers are:\n");
	printf("1 ");
	//search the prime factors inside the random between 1 and pow(target,0.5)
	for (long i = 2; i < pow(target,0.5); ++i)
	{
		//judge the numbers whether are factors or not
		if (target%i != 0)
			//if not, continue,search for next
			continue;
		else 
		{
			//judge the numbers whether are prime or not
			for (j = 2; j <= pow(i,0.5); ++j)
				// if the factor could be divided by prime only once it`s not prime
				if (i%j == 0) break;			
				// if the greatest divisor of the factor greater than the pow(i,0.5)
				// it means the factor is a prime 
				if (j > pow(i,0.5))	printf("%ld ", i);								
		}
	}
	printf("%ld\n",target);
	return 0;
}
