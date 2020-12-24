#include <vector>
#include <iostream>
#include "structs.h"

const char MULTIPLICATION = -1;
const char PLUS = -2;
const char MINUS = -3;
const char DIVISION = -4;

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
            stack.push_back(DIVISION);
            break;

        case '*':
            while (!stack.empty() && stack.back() == DIVISION)
            {
                vent.push_back(stack.back());
                stack.pop_back();
            }
            stack.push_back(MULTIPLICATION);
            break;

        default:
            while (!stack.empty() && (stack.back() == DIVISION || stack.back() == MULTIPLICATION))
            {
                vent.push_back(stack.back());
                stack.pop_back();
            }
            switch (oper)
            {
                case '+':
                    stack.push_back(PLUS);
                    break;
                case '-':
                    stack.push_back(MINUS);
                    break;
            }
    }
}

float Calculate(const char* str)
{
    short i = 0;
    std::vector<int> vent;
    std::vector<int> stack;
    std::vector<short> flagBracket;

    // '0' = x30
    // '9' = x39
    // -1 = x2a = * = MULTIPLICATION
    // -2 = x2b = + = PLUS
    // -3 = x2d = - = MINUS
    // -4 = x2f = / = DIVISION

    // Приоритет
    // (+ = -) < * < /
    //

    // 1 / 2 - 3
    // vent: 1 2 / 3 -
    // stack:
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
                flagBracket.push_back(stack.size());
                break;
            case ')':
                while (stack.size() > flagBracket.back())
                {
                    vent.push_back(stack.back());
                    stack.pop_back();
                }
                flagBracket.pop_back();
                break;
        }
        i++;
    }

    while (!stack.empty())
    {
        vent.push_back(stack.back());
        stack.pop_back();
    }

    std::vector<double> fstack;

    for (int j = 0; j < vent.size(); j++)
    {
        if (vent[j] > 0)
        {
            fstack.push_back(vent[j]);
        }
        else
        {
            float b = fstack.back();
            fstack.pop_back();

            switch (vent[j])
            {
                case MULTIPLICATION:
                    fstack.back() = fstack.back() * b;
                    break;
                case PLUS:
                    fstack.back() = fstack.back() + b;
                    break;
                case MINUS:
                    fstack.back() = fstack.back() - b;
                    break;
                case DIVISION:
                    fstack.back() = fstack.back() / b;
                    break;
            }
        }
    }

    return fstack.back();

}