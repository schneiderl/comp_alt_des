#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.c"
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>

//TODO: usar mutex pra controlar a fila. periogoso fazer dequeues sem bloquear
//TODO: na printDivisors(), ao invés de printar diretamente, concatenar os divisores e printar
// depois, também usando mutex, para evitar os prints serem feitos um sobre outro.
struct Queue* queue;

void printDivisors(int n)
{
    printf("\n%d: ", n);
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            printf("%d ", i);
}

void* threadFunc(void* a){
    if (isEmpty(queue) == false){
        int i; 
       printDivisors(dequeue(queue));
       threadFunc(NULL);
    }
    return 0;
}

int main()
{
    clock_t begin = clock();

    int num, i, threads;
    scanf("%d", &threads); 
    scanf("%d", &num);
    
    queue = createQueue(1000);  


    for(i = 0; i < num; i++) {
        int input;
        scanf("%d", &input);
        enqueue(queue, input);
    }

    pthread_t tid;

    for (i = 0; i < threads; i++)
        pthread_create(&tid, NULL, threadFunc, NULL);
    
    pthread_exit(NULL);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\nTOTAL TIME SPENT: %f ", time_spent);
    return 0;
}

