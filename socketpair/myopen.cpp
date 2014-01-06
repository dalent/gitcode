#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<sys/socket.h>
#include<unistd.h>
#include<fcntl.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
using namespace std;
int read_fd(int ,void *,size_t,int*);
int my_open(const char * pathname, int mode)
{
	int fd, sockfd[2],status;
	pid_t childpid;
	char c, argsockfd[10],argmode[10];
	socketpair(AF_LOCAL, SOCK_STREAM, 0, sockfd);
	if((childpid = fork()) == 0)
	{
		close(sockfd[0]);
		snprintf(argsockfd,sizeof(argsockfd),"%d",sockfd[1]);
		snprintf(argmode,sizeof(argmode),"%d", mode);
		execl("./openfile","openfile", argsockfd,pathname,argmode,(char*)NULL);
		cout << "execl occured"<<endl;
		exit(0);
	}
	close(sockfd[1]);
	waitpid(childpid, &status,0);
	if(WIFEXITED(status) == 0)
	{
		cout <<"not existed"<<endl; 
	}
	if((status = WEXITSTATUS(status)) == 0)
	{
		read_fd(sockfd[0],&c,1,&fd);
	}
	else
	{
		errno =status;
		fd = -1;
	}
	close(sockfd[0]);
	return (fd);
}
