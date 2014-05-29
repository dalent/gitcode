#include<sys/ioctl.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<linux/if.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
using namespace std;
int main()
{
    struct ifreq ifr;
    memset((char*)&ifr,0,sizeof(ifr));

    strncpy(ifr.ifr_name, "eth0", 4);
    int fd = socket(AF_INET, SOCK_DGRAM, 0); 
    if(0 == ioctl(fd, SIOCGIFHWADDR, (char*)&ifr))
    {   
        char buf[32];
        printf("mac %02x:%02x:%02x:%02x:%02x:%02x\n",
                (unsigned char)ifr.ifr_hwaddr.sa_data[0],
                (unsigned char)ifr.ifr_hwaddr.sa_data[1],
                (unsigned char)ifr.ifr_hwaddr.sa_data[2],
                (unsigned char)ifr.ifr_hwaddr.sa_data[3],
                (unsigned char)ifr.ifr_hwaddr.sa_data[4],
                (unsigned char)ifr.ifr_hwaddr.sa_data[5]
                );  
    }   

    if(0 == ioctl(fd, SIOCGIFADDR, (char*)&ifr))
    {   
        printf("ip %s\n",inet_ntoa(((struct sockaddr_in*)&ifr.ifr_addr)->sin_addr));
    }   

}
