#include <iostream>
#include "methods.h"
#include "structs.h"

using namespace std;

int main()
{
    char* str = new char[MAX_STR_LENGTH];
    cout << "Введите выражение: ";
    cin.getline(str, MAX_STR_LENGTH);

    float result;

    Calculate(str, result);

    cout << "Результат выражения: " << result;

    delete[] str;

    return 0;
}
