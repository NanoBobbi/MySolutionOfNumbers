#include <stdio.h>
#include "stdlib.h"
#ifndef Ok
#define Ok 0
#endif
#ifndef Error
#define Error 1
#endif
#ifndef MAX
#define MAX 100
#endif
typedef struct 
{
	long* elem;
	int length;
} *Sequence,array;
//*Sequence means the value inside must be address(pointer)
//int* means declaring the type to be int pointer
//while *vairable means the content of the varible pointer

int Init(Sequence sequence,int limit)
{
	sequence->length = limit;
	sequence->elem = (long*)malloc(limit*sizeof(long));
	if (!sequence->elem)
	{
		printf("Allocate memories for sequence failed!\n");
		return Error;
	}
	return Ok;
}

int Assign(Sequence sequence)
{
	*sequence->elem = 0;
	*(sequence->elem+1) = 1;
	for (int i = 2; i < sequence->length; ++i)
	{
		*(sequence->elem+i) = *(sequence->elem+i-2) + *(sequence->elem+i-1);
	}
	return Ok;
}

int Print_all(Sequence sequence)
{
	printf("All the sequence numbers:\n");
	for (int i = 0; i < sequence->length; ++i)
	{
		printf("%ld  ", *(sequence->elem+i));
	}
	printf("\n");
	return Ok;
}

int Limit(Sequence sequence)
{
	int limit = 0;
	printf("Please input the limit of Fibonacci Numbers\n");
	printf("Up to 93 : ");
	scanf("%d",&limit);
	sequence->length = limit;
	return limit;
}

int main(int argc, char const *argv[])
{
	array sequence;
	int limit;

	limit = Limit(&sequence);
	Init(&sequence,limit);
	Assign(&sequence);
	Print_all(&sequence);

	return 0;
}