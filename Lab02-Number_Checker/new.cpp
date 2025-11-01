#include <bits/stdc++.h>
using namespace std;

string keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do", "double",
    "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register",
    "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef",
    "union", "unsigned", "void", "volatile", "while"};

bool isKeyword(const string &s)
{
    for (string k : keywords)
        if (s == k)
            return true;
    return false;
}

bool isValid(const string &s)
{
    if (!(isalpha(s[0]) || s[0] == '_'))
        return false;
    for (int i = 1; i < s.size(); i++)
    {
        if (!(isalnum(s[i]) || s[i] == '_'))
            return false;
    }
    return true;
}

void checkIdentifiers(const string &code)
{
    string token;
    for (char c : code)
    {
        if (isalnum(c) || c == '_')
        {
            token += c;
        }
        else
        {
            if (!token.empty())
            {
                if (isKeyword(token))
                    cout << token << " - INVALID\n";
                else if (isValid(token))
                    cout << token << " - VALID\n";
                else
                    cout << token << " - INVALID\n";
                token.clear();
            }
        }
    }
    if (!token.empty())
    {
        if (isKeyword(token))
            cout << token << " - INVALID\n";
        else if (isValid(token))
            cout << token << " - VALID\n";
        else
            cout << token << " - INVALID\n";
    }
}

int main()
{
    string code = "int myVar = 10, _temp = myVar; if (myVar > 0) { float 2ndVar; }";
    checkIdentifiers(code);
    return 0;
}
