#include <iostream>
#include "methods.h"

using namespace std;

int main()
{
    char* str = new char[1024];
    cout << "Введите выражение: ";
    cin.getline(str, 1024);

    float result;

    Calculate(str, result);

    cout << "Результат выражения: " << result;

    delete[] str;

    return 0;
}
