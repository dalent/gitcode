#include<stdio.h>
int partition(int*,int,int);
void quicksort(int *array, int low,int high)
{
	if(low >= high)
		return;
	int n =	partition(array, low, high);
	if(n > low+1)
	quicksort(array,low,n-1);
     if(high > n + 1)
	quicksort(array,  n + 1, high);
}
int  partition(int *array,int low, int high)
{
	int tmp = array[low];
	while(low < high)
	{
		while(low < high &&array[high] > tmp)
			high--;
		if(low < high)
			array[low] = array[high];
		while(low < high &&array[low] <= tmp)
			low++;
	   if(low < high)
	   	   array[high] = array[low];
	}

    array[high] = tmp;
    return high;
}


int main()
{
	int array[] = {5,4,3,2,1,6};
	quicksort(array,0, sizeof(array)/sizeof(int)-1);
	for(int i = 0; i < sizeof(array)/sizeof(int);i++)
		printf("%d",array[i]);
	return 0;
}
