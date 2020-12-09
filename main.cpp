#include <iostream>
#include "methods.h"
#include "structs.h"

#define SAY std::cout <<

int main()
{
    char* str = new char[MAX_STR_LENGTH];
    SAY "Введите выражение: ";
    std::cin.getline(str, MAX_STR_LENGTH);

    float result;

    Calculate(str, result);

    SAY "Результат выражения: " << result;

    delete[] str;

    return 0;
}
