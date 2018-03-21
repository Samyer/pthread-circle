/*************************************************************************
	> File Name: pthreadfor.c
	> Author: 
	> Mail: 
	> Created Time: Fri 16 Mar 2018 21:11:37 CST
 ************************************************************************/

#include<stdio.h>
#include<pthread.h>
pthread_mutex_t lock;
void *Print(void*arg)
{
    int i;i=*(int *)arg;
    pthread_mutex_lock(&lock);
    printf("pthread ID:%u  %d\n",pthread_self(),i);
    //printf("%d\n",i);
    pthread_mutex_unlock(&lock);
    return;
}
int main()
{
    pthread_t tha;
    pthread_mutex_init(&lock,NULL);
    int i;int *revital;
    for(i=0;i<5;i++)
    {
        revital=&i;
        pthread_create(&tha,NULL,Print,(void *)revital);
        pthread_detach(tha);
    }
    return 0;
}
