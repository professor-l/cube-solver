#include "header.h"

int heuristic(Cube *C1, Cube *C2);

int sort_piece(Piece P);

int to_pieces(Cube *C, Piece write_to[8]);

int get_xyz(int index, int write_to[3]);

int index_of(Piece P, Piece piece_array[8]);

int compare_cubes(Cube *C1, Cube *C2);

int search(CubeStack *Path, Cube *Goal, int g, int bound);

int contains(CubeStack *P, Cube *C);

int successors(Cube *C, Cube write_to[6], Cube *Goal);

int sort(Cube a[6], int len, Cube *Goal);

#define FOUND -1
#define NOT_FOUND -2
#define INFINITY 100