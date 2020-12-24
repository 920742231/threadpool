#include<stdio.h>
#include<threadpool.h>
#include<unistd.h>
void * task_func(void * arg){
    printf("%ld over\n\r",pthread_self());
}
int main(){
    struct thread_pool * t_pool;
    t_pool = init_pool(100,10,20);
    for(int i=0;i<10;i++)
        t_pool->add(task_func,NULL,t_pool);
    for(int i=0;i<50;i++)
        t_pool->add(task_func,NULL,t_pool);

    t_pool->destory(t_pool);

    return 0;
}

