#include <stdio.h>
#include <assert.h> //for assert
#include <stdlib.h> //for calloc( size_t number, size_t size ); and free( void * ptrmem );
#include <string.h> //for memset( void * memptr, int val, size_t num );
#include <math.h>
#include "stack_functions.c"

int main(){
    struct Stack stk;
    stk_type i;
    StackCtor (&stk, 20);

    StackUnit (&stk);
}

/*
проверка на все ли ок? вопрос из чего все ли ок состоит
    пуш может ли вставить элемент
    проверять выделилась ли память если нет, то как выводить ошибку
шехи
конорейки


*/
