#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.c"
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <string.h>
#include <sys/time.h>

//TODO: usar mutex pra controlar a fila. periogoso fazer dequeues sem bloquear
//TODO: na printDivisors(), ao invés de printar diretamente, concatenar os divisores e printar
// depois, também usando mutex, para evitar os prints serem feitos um sobre outro.
struct Queue* queue;
pthread_mutex_t lock;
typedef struct timespec Time;

void printDivisors(int n)
{
    char destination[5000];
    sprintf(destination, "\n%d: ", n);
    for (int i = 1; i <= n; i++){
        if (n % i == 0){
            char strN[5000];
            sprintf(strN, "%d ", i);
            strcat(destination, strN);
        }
    }
    printf("%s ", destination);
}

void* threadFunc(void* a){
    
    if (isEmpty(queue) == false){
        int i;
        pthread_mutex_lock(&lock);
        int currProcess = dequeue(queue);
        pthread_mutex_unlock(&lock);
       printDivisors(currProcess);
       
       threadFunc(NULL);
       
    }
    
    return NULL;
}

int main()
{
    double t;
    struct timeval begin, end;
    gettimeofday(&begin, 0);


    int num, i, nofthreads;
    scanf("%d", &nofthreads); 
    scanf("%d", &num);

    pthread_t threads[nofthreads];
    
    queue = createQueue(1000);  


    for(i = 0; i < num; i++) {
        int input;
        scanf("%d", &input);
        enqueue(queue, input);
    }

    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("\n mutex init has failed\n");
        return 1;
    }

    pthread_t tid;

    for (i = 0; i < nofthreads; i++){
        pthread_create(&threads[i], NULL, threadFunc, NULL);
    }
    for (i = 0; i < nofthreads; i++){
        pthread_join(threads[i], NULL);
    }

    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;

    printf("\nTOTAL TIME SPENT: %.3f ", elapsed);

    return 0;
}

