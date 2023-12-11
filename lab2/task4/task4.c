#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void shellSort(float* array, size_t size) {
	for (size_t d = size / 2; d > 0; d /= 2)
		for (size_t i = d; i < size; i++)
			for (int j = i - d; j >= 0 && arr[j] > arr[j + d]; j -= d)
				swap(&array[j], &array[j + d]);
    for(int i; i<size; i++){printf("%f", array[])}
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
    // float sortarray=[size];
    // shellSort(array, size);

    // for (int i = 0; i < size; i++){
    //     sortarray[i] == 
    // }

    // for (int i = 0; i < size; i++){
    //     fprintf(output_file, "%f", sortarray);
    // }
    
    // fclose(output_file);
    // return 0;

}