#include<pthread.h>
#include<stdio.h>
#define F_JOINED 8 
int ndone;
int counter= 0;
pthread_mutex_t ndone_mutex = PTHREAD_MUTEX_INITIALIZER;
//pthread_cond_t ndone_cond = PHTREAD_COND_INITIALIZER;
#define NLOOP 500000
void * do_get_read(void*vptr)
{
//	ndone++;

	for(int i = 0; i< NLOOP; i++)
	{
		pthread_mutex_lock(&ndone_mutex);
		int var = counter;
		printf("%ld,%d,\n", pthread_self(), var+1);
		counter = var+1;
		pthread_mutex_unlock(&ndone_mutex);
	}

}
int main(int argc, char ** argv)
{
	pthread_t tidA,tidB;
	pthread_create(&tidA,NULL,&do_get_read, NULL);
	pthread_create(&tidB,NULL,&do_get_read, NULL);
	pthread_join(tidA, NULL);
	pthread_join(tidB,NULL);
}
