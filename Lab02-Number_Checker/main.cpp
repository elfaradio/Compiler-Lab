#include <iostream>
#include <string>
using namespace std;
bool isIden(string inp)
{
    if (isalpha(inp[0]) or inp[0] == '_')
    {
        for (int i = 1; i < inp.size(); i += 1)
        {
            if (isalnum(inp[i]) or inp[i] == '_')
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}
bool isNum(string inp)
{
    bool dot = false, exp = false, d = false;
    ;
    int i = 0;
    if (inp[0] == '+' or inp[0] == '-')
        i += 1;
    for (; i < inp.size(); i += 1)
    {
        if (isdigit(inp[i]))
        {
            d = true;
            continue;
        }
        else if (inp[i] == '.' and dot == false and exp == false)
        {
            dot = true;
        }
        else if ((inp[i] == 'e' or inp[i] == 'E') and exp == false)
        {
            exp = true;
            if (i == 0 or d == false)
            {
                return false;
            }
            if (i + 1 < inp.size() and (inp[i + 1] == '+' or inp[i + 1] == '-'))
            {
                i += 1;
            }
            if (i + 1 > inp.size() or !isdigit(inp[i + 1]))
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    if (d)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{

    string inp;
    cin >> inp;
    if (isIden(inp))
    {
        cout << "Identifier :" << inp << endl;
    }
    else if (isNum(inp))
    {
        cout << "Number :" << inp << endl;
    }
    else
    {
        cout << "is Not Valid";
    }
}