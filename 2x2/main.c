#include "include/header.h"

int main(int argc, char* argv[])
{
    char start[24];
    char end[24];

    Cube C1;
    init(&C1);

    Cube C2;
    init(&C2);

    /*
    Output level
    0 - moves
    1 - states
    2 - both
    */
    int output_level = 0;
    
    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
            if (argv[i][1] == 'h')
            {
                printf("Options:\n");
                printf("    -o [output-level]\n");
                printf("        0: Print moves (default)\n");
                printf("        1: Print cube states\n");
                printf("        2: Print both\n");
                printf("    -s [start-state] (default solved)\n");
                printf("    -e [end-state] (default solved)\n\n");
                printf("Solved cube state: UUUURRRRFFFFDDDDLLLLBBBB\n");
                return 0;
            }
            else if (argv[i][1] == 'o')
            {
                output_level = argv[i + 1][0] - '0';
                if (output_level > 2 || output_level < 0)
                {
                    printf("Output level must be between 0 and 2, inclusive.\n");
                    return 1;
                }
            }

            else if (argv[i][1] == 's')
            {
                if (strlen(argv[i + 1]) != 24)
                {
                    printf("Invalid start state.\n");
                    return 2;
                }
                else
                    memcpy(C1.faces, argv[i + 1], sizeof(C1.faces));
            }

            else if (argv[i][1] == 'e')
            {
                if (strlen(argv[i + 1]) != 24)
                {
                    printf("Invalid end state.\n");
                    return 2;
                }
                else
                    memcpy(C2.faces, argv[i + 1], sizeof(C2.faces));
            }
        }
    }
    
    CubeStack Path;
    init_stack(&Path);

    int t = ida_star(&C1, &C2, &Path);

    for (int j = 1; j < t; j++)
    {
        if (output_level != 1)
            printf("%.2s ", Path.stack[j].last_move);
        
        if (output_level != 0)
            print_cube(&(Path.stack[j]));
    }
    printf("\n");

}
