#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void ShellSort(int n, int mass[])
{
    int i, j, step;
    int tmp;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            tmp = mass[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < mass[j - step])
                    mass[j] = mass[j - step];
                else
                    break;
            }
            mass[j] = tmp;
        }
}



int main(){
    int size;
    printf("Enter the array size\n");
    scanf("%d", &size);

    int max_value;
    printf("Enter the max value\n");
    scanf("%d", &max_value);

    int min_value;
    printf("Enter the min value\n");
    scanf("%d", &min_value);

    float array[size];
    srand(time(NULL));
    for (int i=0; i < size; i++){
        array[i] = (float) rand() / RAND_MAX *(max_value - min_value) + min_value;
        printf("%f\t", array[i]);
    }

    printf("Enter file name");
    FILE *output_file;
    output_file = fopen("file1", "w");
    if (output_file == NULL){
        printf("Error, can't create file\n");
        return 1;
    }

    for (int i = 0; i < size; i++){
        fprintf(output_file, "%f", quickSort(array, 0, size-1));
    }
    fclose(output_file);
    return 0;

}