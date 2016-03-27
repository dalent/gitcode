#include<stdio.h>
void insert(int * array, int n)
{
	for(int i = 1; i < n; i++)
	{
		int tmp = array[i];
		int j = i;
       for(; j > 0;j--)
	   {
	   	   if(array[j-1] > tmp)
	   	   	   array[j] = array[j-1];
		   else 
		   	   break;
	   }
	   array[j] = tmp; 
	}
}

int main(int argc , char** argv)
{
  int array[] = {9,8,7,6,5,4,3,4,2};
  insert(array, sizeof(array)/sizeof(int));
  for(int i = 0; i < sizeof(array)/sizeof(int); i ++)
  	  printf("%d", array[i]);
  return 0;
}
