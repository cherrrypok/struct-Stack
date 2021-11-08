#include "stack_functions.h"


void StackCtor(struct Stack* stk, int capacity)
{
    assert(stk);

    stk->data = (stk_type*) calloc(capacity + 2, sizeof(stk_type));

    if (!stk->data)
	{
		stk->status_error = MEM_ERR;
		return;
	}

    *((canary*) (stk->data))                     = CANARY;
    *((canary*) (stk->data + stk->capacity + 1)) = CANARY;
    printf("%p\n", stk->data);
    stk->data = ++(stk->data);
    printf("%p\n", stk->data);

    stk->size              = 0;
    stk->capacity   = capacity;
    stk->status_error = STK_OK;
}

void StackDtor (struct Stack* stk)
{
    assert (stk);

    memset (stk->data, 0, stk->capacity * sizeof(int));
    free (stk->data);

    stk->size                   = 0;
    stk->capacity               = 0;
    stk->status_error = NOT_CREATED;
}

void StackPush (struct Stack* stk, stk_type value)
{
    if (stk->size == stk->capacity) StackResizeUp (stk);

    if (stk->status_error == MEM_ERR) return;

    stk->data[stk->size++] = value;
}

stk_type StackPop (struct Stack* stk)
{
    if (stk->size == 0)
	{
		stk->status_error = SIZE_ZERO;
		return EMPTY_VALUE;
	}

    if (stk->size * 4 == stk->capacity) StackResizeDown (stk);

    if (stk->status_error == MEM_ERR) return EMPTY_VALUE;

    stk_type pop_el = stk->data[--(stk->size)];
    stk->data[(stk->size)] = EMPTY_VALUE;
    return pop_el;
}

void StackUnit (struct Stack* stk)
{
    stk_type i, num;
    for (i = 1; i < 101; i++)
    {
        StackPush(stk, i);
        printf("valuePush = %f, size = %d\n", i, stk->size);
    }

    for (i = 1; i < 101; i++)
    {
        num = StackPop(stk);
        printf("%f, ", num);
        printf("size = %d\n", stk->size);
    }
}

void StackResizeUp (struct Stack* stk)
{
    stk_type* return_realloc = (stk_type*) realloc (stk->data, stk->capacity * sizeof(stk_type) * 2);

    if (!return_realloc)
	{
		stk->status_error = MEM_ERR;
        return;
	}

    stk->data = return_realloc;

    stk->capacity *= 2;
}

void StackResizeDown (struct Stack* stk)
{
    stk_type* return_realloc = (stk_type*) realloc (stk->data, stk->capacity * sizeof(stk_type) / 2);

    if (!return_realloc)
	{
		stk->status_error = MEM_ERR;
		return;
	}

    stk->data = return_realloc;

    stk->capacity /= 2;
}
