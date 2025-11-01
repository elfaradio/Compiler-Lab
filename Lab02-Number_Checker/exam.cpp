#include <bits/stdc++.h>
using namespace std;

bool isIden(string s)
{
    if (s[0] == '_' or isalpha(s[0]))
    {
        for (int i = 1; i < s.size(); i += 1)
        {
            if (isalnum(s[i]) or s[i] == '_')
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
int main()
{
    string s;
    cin >> s;
    if (isIden(s))
    {
        cout << "Valid" << s << endl;
    }
    else
    {
        cout << "Invalid" << endl;
    }
}