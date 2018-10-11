#include "../include/search.h"
#include <stdlib.h>

int heuristic(Cube *C1, Cube *C2)
{
    int total = 0;

    Piece pieces1[8];
    Piece pieces2[8];
    to_pieces(C1, pieces1);
    to_pieces(C2, pieces2);

    for (int i = 0; i < 8; i++)
    {
        sort_piece(pieces1[i]);
        sort_piece(pieces2[i]);
    }

    for (int j = 0; j < 8; j++)
    {
        int xyz1[3];
        int xyz2[3];

        get_xyz(index_of(pieces1[j], pieces1), xyz1);
        get_xyz(index_of(pieces1[j], pieces2), xyz2);

        for (int k = 0; k < 3; k++)
        {
            total += abs(xyz1[k] - xyz2[k]);
        }

    }

    return total / 4;

}

int sort_piece(Piece P)
{
    if (P[0] > P[2])
    {
        char t = P[0];
        P[0] = P[2];
        P[2] = t;
    }

    if (P[0] > P[1])
    {
        char t = P[0];
        P[0] = P[1];
        P[1] = t;
    }

    if (P[1] > P[2])
    {
        char t = P[1];
        P[1] = P[2];
        P[2] = t;
    }

    return 1;
}

int to_pieces(Cube *C, Piece write_to[8])
{
    write_to[0][0] = C->faces[0];
    write_to[0][1] = C->faces[16];
    write_to[0][2] = C->faces[21];

    write_to[1][0] = C->faces[1];
    write_to[1][1] = C->faces[5];
    write_to[1][2] = C->faces[20];

    write_to[2][0] = C->faces[2];
    write_to[2][1] = C->faces[8];
    write_to[2][2] = C->faces[17];

    write_to[3][0] = C->faces[3];
    write_to[3][1] = C->faces[4];
    write_to[3][2] = C->faces[9];

    write_to[4][0] = C->faces[14];
    write_to[4][1] = C->faces[18];
    write_to[4][2] = C->faces[23];

    write_to[5][0] = C->faces[7];
    write_to[5][1] = C->faces[15];
    write_to[5][2] = C->faces[22];

    write_to[6][0] = C->faces[10];
    write_to[6][1] = C->faces[12];
    write_to[6][2] = C->faces[19];

    write_to[7][0] = C->faces[6];
    write_to[7][1] = C->faces[11];
    write_to[7][2] = C->faces[13];

    return 1;
}

int get_xyz(int index, int write_to[3])
{
    if (index == 0)
    {
        write_to[0] = 0;
        write_to[1] = 0;
        write_to[2] = 0;
    }
    else if (index == 1)
    {
        write_to[0] = 1;
        write_to[1] = 0;
        write_to[2] = 0;
    }
    else if (index == 2)
    {
        write_to[0] = 0;
        write_to[1] = 1;
        write_to[2] = 0;
    }
    else if (index == 3)
    {
        write_to[0] = 1;
        write_to[1] = 1;
        write_to[2] = 0;
    }
    else if (index == 4)
    {
        write_to[0] = 0;
        write_to[1] = 0;
        write_to[2] = 1;
    }
    else if (index == 5)
    {
        write_to[0] = 1;
        write_to[1] = 0;
        write_to[2] = 1;
    }
    else if (index == 6)
    {
        write_to[0] = 0;
        write_to[1] = 1;
        write_to[2] = 1;
    }
    else if (index == 7)
    {
        write_to[0] = 1;
        write_to[1] = 1;
        write_to[2] = 1;
    }
    else
    {
        write_to[0] = -1;
        write_to[1] = -1;
        write_to[2] = -1;
        return 0;
    }
    return 1;
}

int index_of(Piece P, Piece piece_array[8])
{
    for (int i = 0; i < 8; i++)
    {
        if (piece_array[i][0] == P[0] &&
            piece_array[i][1] == P[1] &&
            piece_array[i][2] == P[2])
            {
                return i;
            }
    }
    return -1;
}

int compare_cubes(Cube *C1, Cube *C2)
{
    for (int i = 0; i < 24; i++)
    {
        if (C1->faces[i] != C2->faces[i]) { return 0; }
    }

    return 1;
}