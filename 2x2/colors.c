#include "include/colors.h"

char* red = "\033[38;2;239;83;80m\0";
char* orange = "\033[38;2;255;167;38m\0";
char* yellow = "\033[38;2;255;238;88m\0";
char* green = "\033[38;2;102;187;106m\0";
char* blue = "\033[38;2;66;165;245m\0";
char* white = "\033[38;2;255;255;255m\0";

char* color(char c)
{
    if (c == 'U') { return white; }
    if (c == 'R') { return red; }
    if (c == 'F') { return green; }
    if (c == 'D') { return yellow; }
    if (c == 'L') { return orange; }
    return blue;
}