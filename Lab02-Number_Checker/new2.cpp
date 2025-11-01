#include <iostream>
#include <sstream>
#include <cctype>
using namespace std;

bool isInteger(string s)
{
    for (char c : s)
        if (!isdigit(c))
            return false;
    return !s.empty();
}

bool isFloat(string s)
{
    int dot = 0;
    for (char c : s)
    {
        if (c == '.')
            dot++;
        else if (!isdigit(c))
            return false;
    }
    return dot == 1;
}

bool isHexadecimal(string s)
{
    if (s.size() > 2 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
    {
        for (int i = 2; i < s.size(); i++)
            if (!isxdigit(s[i]))
                return false;
        return true;
    }
    return false;
}

void checkNumbers(string code)
{
    string token;
    stringstream ss(code);

    while (ss >> token)
    {

        if (!token.empty() && (token.back() == ';' || token.back() == ',' || token.back() == ')'))
            token.pop_back();

        if (isInteger(token))
            cout << token << " - INTEGER\n";
        else if (isFloat(token))
            cout << token << " - FLOAT\n";
        else if (isHexadecimal(token))
            cout << token << " - HEXADECIMAL\n";
        else
        {
            if (isdigit(token.back()))
            {
                cout << token << " - Invalid";
            }
        }
    }
}

int main()
{
    string code = "int a = 123; float b = 3.14; int c = 0xAF; double d = 12...2;";
    checkNumbers(code);
    return 0;
}
