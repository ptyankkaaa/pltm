#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define STACK_MAX_SIZE 20
typedef int T;

typedef struct Stack_tag {
    T data[STACK_MAX_SIZE];
    size_t size;
}