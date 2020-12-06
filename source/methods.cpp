#include "structs.h"

void Calculate(const char* str, float& result)
{
    short i = 0;
    short vent[MAX_STR_LENGTH / 2];
    short indexVent = 0;
    char stack[MAX_STR_LENGTH / 2];
    short indexStack = 0;

    // '0' = x30
    // '0' = x39
    // '*' = x2a
    // '+' = x2b
    // '-' = x2d
    // '/' = x2f
    while (str[i] != '\0' && i <= MAX_STR_LENGTH - 1)
    {
        if (str[i] >= '\x30' && str[i] <= '\x39')
        {
            vent[indexVent++] = (short)(str[i] - '0');
        } else if (str[i] == '\x2a' || str[i] == '\x2b' || str[i] == '\x2d' || str[i] == '\x2f')
        {
            stack[indexStack++] = str[i];
        }
        i++;
    }
}