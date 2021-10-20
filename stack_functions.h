typedef double stk_type;
typedef unsigned long long canary;

const canary CANARY = 0xAB0BA1111DEDD0ED;
const stk_type EMPTY_VALUE = NAN;

enum null
{
    NULL_PTR = 0000000000000000
};

enum stk_errors
{
    STK_OK,
    STK_NOT_OK,
    NOT_CREATED,
    MEM_ERR,
    SIZE_ZERO
};

struct Stack
{
    stk_type* data;
    int size,
        capacity,
        status_error;
    stk_type* CANARY_A,
              CANARY_B;
};

void StackCtor (struct Stack* stk, int capacity);
void StackDtor (struct Stack* stk);
void StackPush (struct Stack* stk, stk_type value);
stk_type StackPop (struct Stack* stk);
void StackUnit (struct Stack* stk);
void StackResizeUp (struct Stack* stk);
void StackResizeDown (struct Stack* stk);
