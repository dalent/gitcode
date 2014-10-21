#include<stdio.h>
void insert_sort(int array[], int size)
{
    if(size <= 1)
        return;

    for(int i =2 ;i < size;i ++)
    {
        int k = i;
        int tmp = array[i];
        while(k >0 && array[k - 1] > array[k])
            array[k] = array[k-1];

        array[k] = tmp;
    }
}
