#include "../include/search.h"

int push(CubeStack *S, Cube *C)
{
    if (S->length >= 15) { return 0; }
    copy_cube(&(S->stack[S->length]), C);
    S->length++;
    return 1;
}

int pop(CubeStack *S)
{
    S->length--;
    return 1;
}

int init_stack(CubeStack *S)
{
    S->length = 0;
    return 1;
}