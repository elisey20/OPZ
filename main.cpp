#include <iostream>
#include <cstring>
#include "methods.h"
#include "structs.h"

#define SAY std::cout <<
#define AND <<

int main(int argc, char** argv)
{
    bool flag = true;
    for (int i = 0; i < argc && flag; i++)
        if (!strcmp(argv[i], "-i"))
            flag = false;

    char* str = new char[MAX_STR_LENGTH];
    if (flag)
        SAY "Введите выражение: ";
    std::cin.getline(str, MAX_STR_LENGTH);

    float result;
    try
    {
        result = Calculate(str);
        if (flag)
            SAY "Результат выражения: " AND result;
        else
            SAY result;
    }
    catch (std::logic_error & exception)
    {
        SAY exception.what();
    }

    delete[] str;

    return 0;
}
