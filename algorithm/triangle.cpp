#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000001
int main()
{
	char *mem = (char*)malloc(MAX);
	memset(mem,0, MAX);
	int k;
	scanf("%d",&k);
	while(k--)
	{
		int i=0;
		int m =0;
		scanf("%s", mem);
		unsigned len = strlen(mem);
		while(len--)
		{
				i = (i*10+mem[m++]-'0');
				if(i > 10003)
					i = i % 10003;
		}
		printf("%d\n",i);
	}

	return 0;
}
