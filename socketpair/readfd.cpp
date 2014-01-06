#include<sys/types.h>
#include<sys/socket.h>
#define NULL 0
ssize_t read_fd(int fd, void *ptr, size_t nbytes, int * recvfd)
{

	struct msghdr msg;
	struct iovec iov[1];
	ssize_t n;
	int newfd;
	union{
		struct cmsghdr cm;
		char control[CMSG_SPACE(sizeof(int))];
	
	}control_un;
	struct cmsghdr *cmptr;
	msg.msg_control = control_un.control;
	msg.msg_controllen = sizeof(control_un.control);
	msg.msg_name = NULL;
	msg.msg_namelen = 0;
	iov[0].iov_base = ptr;
	iov[0].iov_len = nbytes;
	msg.msg_iov =iov;
	msg.msg_iovlen = 1;
	if((n = recvmsg(fd,&msg,0)) <= 0)
		return (n);
	if((cmptr = CMSG_FIRSTHDR(&msg)) != NULL && cmptr->cmsg_len == CMSG_LEN(sizeof(int)))
	{
		if(cmptr->cmsg_level != SOL_SOCKET)
			return 1;
		if(cmptr->cmsg_type != SCM_RIGHTS)
			return 1;
		*recvfd = *((int*)CMSG_DATA(cmptr));
	}
	else 
		*recvfd = -1;

	return (n);
}
