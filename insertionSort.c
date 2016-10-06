// insertionSort.c
#include "stdio.h"
#include "stdlib.h"
 /*1,divide the array into two parts ,sorted and unsorted
   2,regard first member as in sorted,others as unsorted
   3,search the next member in unsorted compare with the sorted members
  to locate it`s accurate position recursively 
   4,until get all the members`positions */

void swap(int *a,int *b)
{
	int temp = 0;
	temp = *a;	
	*a = *b;
	*b = temp;
}

void all(int *array,int length)
{
	for (int i = 0; i < length; ++i)
	{
		printf("%d  ", *(array+i));
	}
	printf("\n");
}

int insertionSort(int *array,int length)
{
	//set pointer point to the first array address
	int *pointer = array;
	// outer loop means the range of the sorted array and first unsorted member
	//and consider the first member as sorted 
	// after sorting the first unsorted member,escalate the range gradually
	for (int i = 1; i < length; ++i)
	{
		//inner loop means find the position for the first unsorted array in sorted 
		for (int j = 0; j < i; ++j)
		{	
			//if the current bigger than the previous member,swap them
			if (*(array+i-j) < *pointer)
			{
				swap(array+i-j,array+i-1-j);
				// if swap successfully change pointer to last
				pointer --;
			}
			//else break out the inner loop
			else break;
		// set pointer point to the last sorted member address every time 
		pointer = array +i;
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	int *array;
	int length = 0;

	printf("Please input the length of array:");
	scanf("%d",&length);

	array = (int*) malloc(length * sizeof(int));
	for (int i = 0; i < length; ++i)
	{
		printf("the array[%d]:", i);
		scanf("%d",array+i);
	}

	insertionSort(array,length);
	all(array,length);
	return 0;
}