#include <iostream>
#include "methods.h"
#include "structs.h"

#define SAY std::cout <<

int main()
{
    //char* str = new char[MAX_STR_LENGTH];
    const char* str = "(12-2)*(9/3+4560)/(156-4861*2)-(125/5+45-81*5846/51+651*584-651+18/8431)";
    //SAY "Введите выражение: ";
    //std::cin.getline(str, MAX_STR_LENGTH);

    float result;

    Calculate(str, result);

    SAY "Результат выражения: " << result;

    //delete[] str;

    return 0;
}
