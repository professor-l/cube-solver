#include <string.h>
#include <stdio.h>
#include "colors.h"

typedef struct
{
    char faces[24];
    char last_move[2];
} Cube;

typedef struct
{
    Cube stack[15];
    int length;
} CubeStack;

int push(CubeStack *S, Cube *C);
int pop(CubeStack *S);
int init_stack(CubeStack *S);

typedef char Piece[3];

int init(Cube *C);

int print_cube(Cube *C);

int move(Cube *C, char *m);

int copy_cube(Cube *C1, Cube *C2);

int ida_star(Cube *Start, Cube *Goal, CubeStack *Path);