#include<stdio.h>
int partition(int * array, int low, int high)
{
	int tmp = array[low];
	while(low !=  high)
	{
		while(low != high && array[high] > tmp)
			high--;
		if(low != high)
			array[low] = array[high];
		while(low != high && array[low] < tmp)
			low++;
		if(low != high)
			array[high] = array[low];
	}
	array[low] = tmp;
	return low;
}
int  search(int *array, int low, int high,int pos)
{
	int rack = array[0];
	int n = partition(array, low, high);
	if(n > pos)
		search(array,low,n-1, pos);
	else if (n < pos)
		search(array, n + 1, high,pos);
	else 
		return array[n];
}
int main()
{
	for(int i = 3; i >=0; i--)
	{

		int array[] = {5,4,2,3,1};
		printf("%d",search(array,0, sizeof(array)/sizeof(int) -1,i));
	}
}
