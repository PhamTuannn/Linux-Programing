#include<stdio.h>
#include<pthread.h>

struct start_end{
    int start;
    int end;
};
unsigned long sum;
unsigned long ret1 = 0;
unsigned long ret2 = 0;
int i = 0;

void *myThreadSum(void *vargp)
{
    struct start_end *data = (struct start_end *)vargp;
    int i = 0;
    unsigned long local_sum = 0;
    for(i = data->start; i < data->end; i++)
    {
        local_sum = local_sum + i;
    }
    return (void *)local_sum;
}

int main()
{
    pthread_t thread1;
    pthread_t thread2;
    struct start_end data1 = {0, 500000000};
    struct start_end data2 = {500000000, 1000000000};
    
    pthread_create(&thread1, NULL, myThreadSum, (void *)&data1);
    pthread_create(&thread2, NULL, myThreadSum, (void *)&data2);
    pthread_join(thread1, (void *)&ret1);
    pthread_join(thread2, (void *)&ret2);
    sum = ret1 + ret2;
    printf("%lu", sum);
    return 0;
}
