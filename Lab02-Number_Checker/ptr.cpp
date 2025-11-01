#include <bits/stdc++.h>
using namespace std;

bool isIden(const char *inp)
{
    if (isalpha(*inp) || *inp == '_')
    {
        inp++;
        while (*inp)
        {
            if (isalnum(*inp) || *inp == '_')
                inp++;
            else
                return false;
        }
        return true;
    }
    return false;
}

bool isNum(const char *inp)
{
    bool dot = false, exp = false, d = false;

    if (*inp == '+' || *inp == '-')
        inp++;

    while (*inp)
    {
        if (isdigit(*inp))
        {
            d = true;
            inp++;
        }
        else if (*inp == '.' && !dot && !exp)
        {
            dot = true;
            inp++;
        }
        else if ((*inp == 'e' || *inp == 'E') && !exp)
        {
            exp = true;
            if (!d)
                return false;
            inp++;
            if (*inp == '+' || *inp == '-')
                inp++;
            if (!isdigit(*inp))
                return false;
        }
        else
            return false;
    }

    return d;
}

int main()
{
    int n;

    cin >> n;

    char ans[n][100];

    for (int i = 0; i < n; i++)
    {
        cin >> ans[i];
    }

    for (int i = 0; i < n; i++)
    {
        char *ptr = ans[i];
        if (isIden(ptr))
        {
            cout << "Identifier : " << ptr << endl;
        }
        else if (isNum(ptr))
        {
            cout << "Number     : " << ptr << endl;
        }
        else
        {
            cout << "Not Valid  : " << ptr << endl;
        }
    }

    return 0;
}
