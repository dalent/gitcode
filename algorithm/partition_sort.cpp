#include<iostream>
using namespace std;
#define CNT 100
char  tmp[CNT];
void combine(int* array1, int m, int * array2, int n)
{
	int t = 0;
	int i = 0, j = 0;
	while(i < m && j < n)
	{
		int tmp_1 = 0;
		if( array1[i] > array2[j])
			tmp_1 = array1[i++];
		else
			tmp_1 = array2[j++];

		tmp[t++] = tmp_1;
	}

	while(i < m)
		tmp[t++] = array1[i++];

	while( j < n)
		tmp[t++] = array2[j++];
	

	for(int k = 0; k < m + n; k++)
	{
		array1[k] = tmp[k];
	}

		


}
void partion_sort(int *array, int n)
{
	if(n <= 1)
		return;

	int m = n / 2;
	partion_sort(array, m);
	partion_sort(array + m , n - m);
	combine(array,m, array + m, n - m);
}
int main()
{
	int array[] = {5,4,5,7,8,6,9,10};
	partion_sort(array, sizeof(array)/sizeof(int));
	for(int i = 0; i < sizeof(array)/sizeof(int); i++)
		cout <<array[i] << endl;
	return 0;


}
