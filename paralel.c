#include <stdio.h>
#include <stdlib.h>

void printDivisors(int n)
{
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            printf("%d\n", i);
}

int main()
{
    int num, *input, i;
    scanf("%d", &num);
    input = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", input + i);
    }
    
    for(i = 0; i < num; i++){
        printDivisors(input[i]);
    }
        
    return 0;
}

