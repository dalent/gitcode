#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
using namespace std;
int my_open(const char *, int);
int main(int argc, char ** argv)
{
	int fd,n;
	char buff[1024];
	if(argc != 2)
	{
		cout << "argu not 2"<<endl;
		return 1;
	}
	if((fd = my_open(argv[1],O_RDONLY)) < 0)
	{
		cout << "open failed";
		return 1;
	}
	while((n = read(fd, buff, 1024))> 0)
			write(STDOUT_FILENO ,buff, n);
			
	return 0;
}
