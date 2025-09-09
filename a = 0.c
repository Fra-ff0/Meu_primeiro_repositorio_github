#include <stdio.h>
#include <stdlib.h>

    int main(){
        int *numbers[10];
        int size = 10;

        numbers[10] = (int*)malloc(size * sizeof(int));
        for(int i = 0; i < size; i++)
            numbers[i] = i;
        
        for(int i = 0; i < size; i++)
            printf("%i\n",numbers [i]);
        
        free(numbers);

        return 0;
    } 