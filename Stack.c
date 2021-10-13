#include <stdio.h>
#include <assert.h> //for assert
#include <stdlib.h> //for calloc( size_t number, size_t size ); and free( void * ptrmem );
#include <string.h> //for memset( void * memptr, int val, size_t num );

struct Stack{
    int* data;
    int size;
    int capacity;
};

int StackCtor(struct Stack* stack, int capacity);
int StackDtor(struct Stack* stack);
int StackPush(struct Stack* stack, int value);
int StackPop(struct Stack* stack);

int main(){
    struct Stack stack = {0};
    int capacity = 10, value, i;

    StackCtor(&stack, 20);
    for (i = 0; i < 21; i++){
        StackPush(&stack, i + 1);
        printf("valuePush = %d, size = %d\n", i + 1, stack.size);
    }
    for (i = 0; i < 21; i++){
        printf("%d, ", StackPop(&stack));
        printf("size = %d\n", stack.size);
    }
}

int StackCtor(struct Stack* stack, int capacity){
    assert(stack);
    stack->data = calloc(capacity, sizeof(int));
    stack->size = 0;
    stack->capacity = capacity;
}

int StackDtor(struct Stack* stack){
    assert(stack);
    memset(stack->data, 0, stack->capacity * sizeof(int));
    stack->size = -1;
    stack->capacity = -1;
    free(stack->data);
}

int StackPush(struct Stack* stack, int value){
    assert(stack);
    if(stack->size < stack-> capacity)
        stack->data[stack->size++] = value;
    else
        return -1;
}

int StackPop(struct Stack* stack){
    assert(stack);
    if (stack->size != 0){
        stack->size--;
        return stack->data[stack->size];
    }
    return -1;
}
