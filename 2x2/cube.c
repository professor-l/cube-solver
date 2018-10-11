#include "include/header.h"

int init(Cube* C)
{
    memcpy(C->faces, "UUUURRRRFFFFDDDDLLLLBBBB", sizeof(char) * 24);
    C->last_move[0] = 'x';
    C->last_move[1] = ' ';
    return 1;
}

int print_cube(Cube* C)
{
    printf("\n");
    printf("    %s@ %s@\n", color(C->faces[0]), color(C->faces[1]));

    printf("    %s@ %s@\n", color(C->faces[2]), color(C->faces[3]));



    printf("%s@ %s@ %s@ %s@ %s@ %s@\n",
        color(C->faces[16]), color(C->faces[17]),
        color(C->faces[8]), color(C->faces[9]),
        color(C->faces[4]), color(C->faces[5]));

    printf("%s@ %s@ %s@ %s@ %s@ %s@\n",
        color(C->faces[18]), color(C->faces[19]),
        color(C->faces[10]), color(C->faces[11]),
        color(C->faces[6]), color(C->faces[7]));



    printf("    %s@ %s@\n", color(C->faces[12]), color(C->faces[13]));

    printf("    %s@ %s@\n", color(C->faces[14]), color(C->faces[15]));

    printf("    %s@ %s@\n", color(C->faces[23]), color(C->faces[22]));

    printf("    %s@ %s@\n", color(C->faces[21]), color(C->faces[20]));

    printf("\n");
    return 1;
}

int u(Cube *C)
{
    C->last_move[0] = 'U';
    C->last_move[1] = ' ';

    char t1;
    char t2;

    t1 = C->faces[4];
    t2 = C->faces[5];

    C->faces[4] = C->faces[20];
    C->faces[5] = C->faces[21];

    C->faces[20] = C->faces[16];
    C->faces[21] = C->faces[17];

    C->faces[16] = C->faces[8];
    C->faces[17] = C->faces[9];

    C->faces[8] = t1;
    C->faces[9] = t2;

    t1 = C->faces[0];
    C->faces[0] = C->faces[2];
    C->faces[2] = C->faces[3];
    C->faces[3] = C->faces[1];
    C->faces[1] = t1;

    return 1;
}

int up(Cube *C)
{

    C->last_move[0] = 'U';
    C->last_move[1] = '\'';

    char t1;
    char t2;

    t1 = C->faces[4];
    t2 = C->faces[5];

    C->faces[4] = C->faces[8];
    C->faces[5] = C->faces[9];

    C->faces[8] = C->faces[16];
    C->faces[9] = C->faces[17];

    C->faces[16] = C->faces[20];
    C->faces[17] = C->faces[21];

    C->faces[20] = t1;
    C->faces[21] = t2;

    t1 = C->faces[0];

    C->faces[0] = C->faces[1];
    C->faces[1] = C->faces[3];
    C->faces[3] = C->faces[2];
    C->faces[2] = t1;

    return 1;
}

int r(Cube *C)
{

    C->last_move[0] = 'R';
    C->last_move[1] = ' ';

    char t1;
    char t2;

    t1 = C->faces[1];
    t2 = C->faces[3];

    C->faces[1] = C->faces[9];
    C->faces[3] = C->faces[11];

    C->faces[9] = C->faces[13];
    C->faces[11] = C->faces[15];

    C->faces[13] = C->faces[22];
    C->faces[15] = C->faces[20];

    C->faces[20] = t2;
    C->faces[22] = t1;

    t1 = C->faces[4];
    C->faces[4] = C->faces[6];
    C->faces[6] = C->faces[7];
    C->faces[7] = C->faces[5];
    C->faces[5] = t1;

    return 1;
}

int rp(Cube* C)
{

    C->last_move[0] = 'R';
    C->last_move[1] = '\'';

    char t1;
    char t2;

    t1 = C->faces[1];
    t2 = C->faces[3];

    C->faces[1] = C->faces[22];
    C->faces[3] = C->faces[20];

    C->faces[20] = C->faces[15];
    C->faces[22] = C->faces[13];

    C->faces[13] = C->faces[9];
    C->faces[15] = C->faces[11];

    C->faces[9] = t1;
    C->faces[11] = t2;

    t1 = C->faces[4];
    C->faces[4] = C->faces[5];
    C->faces[5] = C->faces[7];
    C->faces[7] = C->faces[6];
    C->faces[6] = t1;

    return 1;

}

int f(Cube *C)
{

    C->last_move[0] = 'F';
    C->last_move[1] = ' ';

    int t1;
    int t2;

    t1 = C->faces[2];
    t2 = C->faces[3];

    C->faces[2] = C->faces[19];
    C->faces[3] = C->faces[17];

    C->faces[17] = C->faces[12];
    C->faces[19] = C->faces[13];

    C->faces[12] = C->faces[6];
    C->faces[13] = C->faces[4];

    C->faces[4] = t1;
    C->faces[6] = t2;

    t1 = C->faces[8];
    C->faces[8] = C->faces[10];
    C->faces[10] = C->faces[11];
    C->faces[11] = C->faces[9];
    C->faces[9] = t1;

    return 1;
}

int fp(Cube *C)
{

    C->last_move[0] = 'F';
    C->last_move[1] = '\'';

    int t1;
    int t2;

    t1 = C->faces[2];
    t2 = C->faces[3];

    C->faces[2] = C->faces[4];
    C->faces[3] = C->faces[6];

    C->faces[4] = C->faces[13];
    C->faces[6] = C->faces[12];

    C->faces[12] = C->faces[17];
    C->faces[13] = C->faces[19];

    C->faces[17] = t2;
    C->faces[19] = t1;

    t1 = C->faces[8];
    C->faces[8] = C->faces[9];
    C->faces[9] = C->faces[11];
    C->faces[11] = C->faces[10];
    C->faces[10] = t1;

    return 1;
}

int move(Cube *C, char* m)
{
    if (m[0] == 'R')
    {
        if (m[1] == ' ') { return r(C); }
        else { return rp(C); }
    }

    if (m[0] == 'U')
    {
        if (m[1] == ' ') { return u(C); }
        else { return up(C); }
    }

    if (m[0] == 'F')
    {
        if (m[1] == ' ') { return f(C); }
        else { return fp(C); }
    }

    return 0;
}

int copy_cube(Cube *C1, Cube *C2)
{
    memcpy(C1->faces, C2->faces, sizeof(char) * 24);
    C1->last_move[0] = C2->last_move[0];
    C1->last_move[1] = C2->last_move[1];

    return 1;
}