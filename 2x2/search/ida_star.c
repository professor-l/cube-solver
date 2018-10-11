#include "../include/search.h"

int ida_star(Cube *Start, Cube *Goal, CubeStack *Path)
{
    int bound = heuristic(Start, Goal);

    push(Path, Start);

    while (1)
    {
        int t = search(Path, Goal, 0, bound);

        if (t == FOUND) { return Path->length; }
        if (t == INFINITY) { return NOT_FOUND; }

        bound = t;
    }

    return NOT_FOUND;
}

int search(CubeStack *Path, Cube *Goal, int g, int bound)
{
    Cube Node = Path->stack[Path->length - 1];

    int f = g + heuristic(&Node, Goal);

    if (f > bound) { return f; }

    if (compare_cubes(&Node, Goal)) { return FOUND; }

    int min = INFINITY;

    Cube successor_list[6];
    int successor_count = successors(&Node, successor_list, Goal);

    for (int i = 0; i < successor_count; i++)
    {

        Cube Succ = successor_list[i];

        if (!contains(Path, &Succ)) {

            push(Path, &Succ);

            int t = search(Path, Goal, g + 1, bound);

            if (t == FOUND) { return FOUND; }

            if (t < min) { min = t; }

            pop(Path);

        }
    }

    return min;

}

int contains(CubeStack *P, Cube *C)
{
    for (int i = 0; i < P->length; i++)
    {
        if (compare_cubes(&(P->stack[i]), C))
        {
            return 1;
        }
    }
    return 0;
}

int successors(Cube *C, Cube write_to[6], Cube *Goal)
{
    char moves[6][2] = {"U ", "U'", "R ", "R'", "F ", "F'"};

    for (int m = 0; m < 6; m++)
    {
        copy_cube(&(write_to[m]), C);
        move(&(write_to[m]), moves[m]);
    }

    sort(write_to, 6, Goal);
    return 6;
}

int sort(Cube a[6], int len, Cube *Goal)
{
    int h[len];
    for (int j = 0; j < len; j++)
    {
        h[j] = heuristic(&(a[j]), Goal);
    }

    int n = len;
    int swapped = 1;
    while (swapped == 1)
    {
        swapped = 0;
        for (int i = 1; i < n; i++)
        {
            if (h[i - 1] > h[i])
            {
                int t = h[i - 1];
                h[i - 1] = h[i];
                h[i] = t;

                Cube T;
                copy_cube(&T, &(a[i - 1]));
                copy_cube(&(a[i - 1]), &(a[i]));
                copy_cube(&(a[i]), &T);
                swapped = 1;
            }
        }
        n--;
    }
    return 1;
}