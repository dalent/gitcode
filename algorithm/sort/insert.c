#include<stdio.h>
void insert_sort(int array[], int size)
{
    if(size <= 1)
        return;

    for(int i =1 ;i < size;i++)
    {
        int k = i;
        int tmp = array[i];
        while(k > 0 && array[k - 1] > tmp)
        {
            array[k] = array[k-1];
            k--;
        }


        array[k] = tmp;
    }
}

int main()
{
    int array[10] = {10,9,8,7,6,5,4,3,2,1};
    insert_sort(array,10);
    for(int i =0; i < sizeof(array)/sizeof(int); i++)
        printf("%d\n", array[i]);
}
