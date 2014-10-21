#include<stdio.h>
int main()
{
	FILE* pFile = popen("ping -c 1 -W 2 1.2.4.8", "r");
	char sql[2048];
	while(fread(sql,1,sizeof(sql), pFile) != 0);
	printf("%s",sql);
	pclose(pFile);
}
