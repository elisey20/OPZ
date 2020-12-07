#include <vector>
#include <cmath>
#include <iostream>
#include "structs.h"



int getNumber(const char* str, short& i)
{
    int res = 0;
    char rank = 0;
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        i++;
        rank++;
    }
    if (rank >= 6)
        throw std::logic_error("Введенно слишком большое число");
    i--;
    return res;
}

void goToStack(std::vector<int>& vent, std::vector<int>& stack, char oper)
{
    switch (oper)
    {
        case '/':
            stack.push_back(-4);
            break;

        case '*':
            while (!stack.empty() && stack.back() == -4)
            {
                vent.push_back(stack.back());
                stack.pop_back();
            }
            stack.push_back(-1);
            break;

        default:
            while (!stack.empty() && (stack.back() == -4 || stack.back() == -1))
            {
                vent.push_back(stack.back());
                stack.pop_back();
            }
            switch (oper)
            {
                case '+':
                    stack.push_back(-2);
                    break;
                case '-':
                    stack.push_back(-3);
                    break;
            }
            break;
    }
}

void Calculate(const char* str, float& result)
{
    result = 0;
    short i = 0;
    std::vector<int> vent;
    std::vector<int> stack;
    short flagBracket = -1;

    // '0' = x30
    // '9' = x39
    // -1 = x2a = *
    // -2 = x2b = +
    // -3 = x2d = -
    // -4 = x2f = /

    // Приоритет
    // (+ = -) < * < /
    //

    // 1 / 2 - 3
    // vent: 1 2 / 3 -
    // stack:
    try
    {
        while (str[i] != '\0' && i <= MAX_STR_LENGTH - 1)
        {
            switch (str[i])
            {
                case '0'...'9':
                    vent.push_back(getNumber(str, i));
                    break;
                case '+':
                    goToStack(vent, stack, '+');
                    break;
                case '-':
                    goToStack(vent, stack, '-');
                    break;
                case '*':
                    goToStack(vent, stack, '*');
                    break;
                case '/':
                    goToStack(vent, stack, '/');
                    break;
                case '(':
                    flagBracket = stack.size();
                    break;
                case ')':
                    while (stack.size() > flagBracket)
                    {
                        vent.push_back(stack.back());
                        stack.pop_back();
                    }
                    flagBracket = -1;
                    break;
            }
            i++;
        }
    }
    catch (std::logic_error& exception)
    {
        std::cout << exception.what() << '\n';
        result = 0;
        return;
    }

    while (!stack.empty())
    {
        vent.push_back(stack.back());
        stack.pop_back();
    }

    std::vector<float> fstack;

    for (int j = 0; j < vent.size(); j++)
    {
        if (vent[j] > 0)
        {
            fstack.push_back(vent[j]);
        }
        else
        {
            int b = fstack.back();
            fstack.pop_back();

            switch (vent[j])
            {
                case -1:
                    fstack.back() = fstack.back() * b;
                    break;
                case -2:
                    fstack.back() = fstack.back() + b;
                    break;
                case -3:
                    fstack.back() = fstack.back() - b;
                    break;
                case -4:
                    fstack.back() = fstack.back() / b;
                    break;
            }
        }
    }

    result = fstack.back();

}