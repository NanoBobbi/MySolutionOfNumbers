#include<stdio.h>
#include<stdlib.h>
int get_target(int target)
{
    scanf("%d",&target);
    return target;
}
//int* arrary:array is declared as int pointer(int*)
//Using malloc() to allocate memories for array needn`t to write as below:
//*array = malloc(***); false
//array = malloc(***); right,we have declared array as int*
int init_array(int length,int* array)
{
    array =  (int*)malloc(length*sizeof(int));
    if(!array) printf("Initialize array error!");
    return 1;
}

int get_array_values(int length,int* array)
{
    int i = length;
    for (int i = 0; i < length; i++)
    {
        printf("The number %d:", i);
        scanf("%d",array+i);
    }
    return 1;
}

int print_all_array(int length,int* array)
{
    int i = length;
    for (int i = 0; i < length; ++i)
    {
        printf("%d ", *(array+i));
    }
    return 1;
}

int find_indices(int length,int *array,int target)
{
    int sum = 0,flag = 1;
    for (int i = 0; i < length; ++i)
    {
        for (int j = i; j < length; ++j)
        {
            sum = *(array+i) + *(array + j);
            if (sum == target)
            {
                if(printf("%d and %d\n", i,j))
                flag = 0;
            }
            sum = 0;
        }
    }
    if(flag) printf("None of the indices have been found!\n");
    return 1;
}

int main()
{
    int* array;
    //Same as mentioned above.Using *array repesent the array pointer is needless and false
    int length = 0,target;

    printf("Hello! Welcome to TwoSum.\n\n");

    printf("Please input the target number:\n");
    target = get_target(target);

    printf("Please input the length of the array:\n");
    scanf("%d",&length);
    if(init_array(length,array))
    printf("OK!\n");


    printf("Please input the array numbers you like:\n");
    if(get_array_values(length,array))
    printf("OK!\n");

    printf("the vaild numbers you input:\n");
    if(print_all_array(length,array))
    printf("\nOK!\n");

    printf("The sum of the two numbers` indices:\n");
    if(find_indices(length,array,target))
    printf("OK!\n");

    return 0;
}
