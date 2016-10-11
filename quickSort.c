// quickSort.c
#include "stdio.h"
#include "stdlib.h"


void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void all(int *array,int length)
{
	for (int i = 0; i < length; ++i)
	{
		printf("%d 	",*(array+i));
	}
	printf("\n");
}
int quickSort(int *a,int left,int right)
{
	int pivot;
	int i = left,j = right;

    if(left>right)	return 1;
                                    
    pivot=*(a+left); //pivot中存的就是基准数
 
    while(i!=j)
    {
       //顺序很重要，要先从右边开始找
       while(*(a+j) >= pivot && i<j)	j--;
       //再找右边的
       while(*(a+i) <= pivot && i<j)	i++;
       //交换两个数在数组中的位置
       if(i<j)  swap(a+i,a+j);
    }
    //最终将基准数归位
    *(a+left) = *(a+i);
    *(a+i) = pivot;
    // all(a,right-left);
    quickSort(a,left,i-1);//继续处理左边的，这里是一个递归的过程
    quickSort(a,i+1,right);//继续处理右边的 ，这里是一个递归的过程

    return 0;
}

int main(int argc, char const *argv[])
{
	int *array;
	int length = 0;

	printf("Please input the length of the array\n");
	scanf("%d",&length);
	array = (int*) malloc(length * sizeof(int));

	for (int i = 0; i < length; ++i)
	{
		printf("array %d:", i+1);
		scanf("%d",array+i);
	}

	quickSort(array,0,length-1);
	all(array,length);
	return 0;
}