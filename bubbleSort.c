// bubbleSort.c
#include "stdio.h"	
#include "stdlib.h"
#ifndef Ok
#define Ok 0
#endif
#ifndef Error
#define Error 1
#endif

int init(int *array,int length)
{
	array = (int*) malloc(length * sizeof(int));
	if (!array)
	{
		printf("Allocate memories failed!\n");
		return Error;
	}
	return Ok;
}

int assign(int *array,int length)
{
	int i;
	for (i = 0; i < length; ++i)
	{
		printf("Please input the number %d: ", i+1);
		scanf("%d",(array+i));
	}
	return Ok;
}

int bubbleSort(int *array,int length)
{
	int temp;
	// The max index of the array is length there can`t be array[length]
	// and it only needs length-1 loops among in outer loop
	for (int j = 0; j < length-1; ++j)
	{
		// inner loop makes the biggest value down to the last palce
		//while outer loop index increased,the range of array narrowed
		for (int i = 0; i < length-1-j; ++i)
		{
			// if previous member bigger than subsequent member
			// exchange their value
			if (*(array+i) > *(array+i+1))
			{
				temp = *(array+i);
				*(array+i) = *(array+i+1);
				*(array+i+1) = temp;
			}
		}
	}
	return Ok;
}

int all(int *array,int length)
{
	for (int i = 0; i < length; ++i)
	{
		printf("%d\n", *(array+i));
	}
	return Ok;
}
int main(int argc, char const *argv[])
{
	int *array;
	int length = 0;

	printf("Please input the length of the array\n");
	scanf("%d",&length);
	init(array,length);

	assign(array,length);
	printf("The array has sorted ascendingly as followed!\n");
	bubbleSort(array,length);
	all(array,length);


	return 0;
}
