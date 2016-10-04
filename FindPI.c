#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	int decimal = 0;
	printf("Please input the number of decimal places:\n");
	printf("Note:Up to 49 decimal limit!\n");
	scanf("%d",&decimal);
	printf("%.*f\n", decimal,M_PI);
	// the decimal argument before the float argument
	return 0;
}