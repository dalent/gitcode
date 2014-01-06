#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
using namespace std;
int write_fd(int ,void *,size_t,int);
int main(int argc, char ** argv)

{
	int fd;
	ssize_t n;
	if(argc != 4)
	{
		cout<<"argc not 4"<<endl;
		return 1;
	}
	if((fd = open(argv[2], atoi(argv[3]))) <0)
	{
		cout<<"open failed"<<endl;
		return 1;
	}
	if((n = write_fd(atoi(argv[1]),(void*)"",1,fd))<0)
	{
		cout<<"write failed"<<endl;
		return 1;
	}


}
