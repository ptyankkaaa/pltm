#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int size;
    printf("Enter the array size\n");
    scanf("%d", &size);

    int array[size];
    for (int i = 0; i < size; i++) {
        array[i] = rand()%100;
        printf("%d\t", array[i]);
    }
    
    return 0;
}