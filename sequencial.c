#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.c"
#include <string.h>

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
    clock_t begin = clock();

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
    
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\nTOTAL TIME SPENT: %f ", time_spent);
    return 0;
}

