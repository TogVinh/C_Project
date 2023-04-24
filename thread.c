#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *worker(void *data)
{
    int i;
    char *name = (char*)data;
    for (i = 0; i <120 ; i++)
    {
        usleep(50000);
        printf("hi name = %s\n", name);
    }
    printf("thread %s done \n", name);

}

int main()
{
    pthread_t th1, th2;
    pthread_create(&th1, NULL, worker, "X");
    pthread_create(&th2, NULL, worker, "Y");
    sleep(5);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    // printf("====> Cancelling Thread Y!!\n");
    // pthread_cancel(th2);
    // usleep(100000);
    // printf("====> Cancelling Thread X!\n");
    // pthread_cancel(th1);
    // printf("exiting from main program\n");

    return 0;
}