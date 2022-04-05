#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.c"
#include <string.h>
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

int main()
{
    double t;
    Time start_time, end_time;
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, (struct timespec *) &start_time);

    int num, i;
    scanf("%d", &num);
    struct Queue* queue = createQueue(1000);


    for(i = 0; i < num; i++) {
        int input;
        scanf("%d", &input);
        enqueue(queue, input);
    }
    
    for(i = 0; i < num; i++){
        printDivisors(dequeue(queue));
    }
    
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, (struct timespec *) &end_time);
    t = (double) (end_time.tv_sec - start_time.tv_sec ) + (double) (end_time.tv_nsec - start_time.tv_nsec) * 1e-9;

    printf("\nTOTAL TIME SPENT: %f ", t);
    return 0;
}

