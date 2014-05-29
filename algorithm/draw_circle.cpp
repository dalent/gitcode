#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define R  10
int main()
{
	double y;
	int x, m;
	for(y = 10; y >= -10; y--)
	{
		m =  2.5 * sqrt(100 - y * y);
		for(x = 1; x < 40 - m ; x++)
			printf(" ");
		printf("*");
		for(; x < 40 +m ; x++)
			printf(" ");
		printf("*\n");
	}
	return 0;
}
