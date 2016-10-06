// selectionSort.c
#include "stdio.h"
#include "stdlib.h"

int all(int *array,int length)
{
	for (int i = 0; i < length; ++i)
	{
		printf("%d 	", *(array+i));
	}
	printf("\n");
	return 0;
}

int selectionSort(int *array,int length)
{
	int max = 0,temp;
	//outer loop narrows the range of array
	//everytime exclude the last
	for (int j = 0; j < length-1; ++j)
	{
		// reset the max index to the head 
		max = 0;
		// search the max value index in the array which scaled down gradually
		for (int i = 0; i < length-1-j; ++i)
		{
			//if subsequent member bigger than the max,set the max 
			if (*(array+max) < *(array+i+1))
			{
				max = i+1;
			}
		}
		// exchange the values of max and last
		temp = *(array+max);
		*(array+max) = *(array+length-1-j);
		*(array+length-1-j) = temp;
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	int *array,length = 0;

	printf("Please input the length of array:");
	scanf("%d",&length);

	array = (int*) malloc(length * sizeof(int));

	for (int i = 0; i < length; ++i)
	{
		printf("The member %d:", i+1);
		scanf("%d",array+i);
	}

	all(array,length);
	selectionSort(array,length);
	printf("The array have been selection sorted ascendingly as below!\n");
	all(array,length);
	return 0;
}