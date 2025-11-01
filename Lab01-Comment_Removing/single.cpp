#include <bits/stdc++.h>
using namespace std;

int main()
{
    FILE *in = fopen("a.c", "r");
    FILE *out = fopen("output.c", "w");

    if (!in || !out)
    {
        cout << "Cannot open file!" << endl;
        return 1;
    }

    char ans[100000];
    char *x = ans;
    int c;
    while ((c = fgetc(in)) != EOF)
    {
        *x++ = c;
    }
    *x = '\0';
    fclose(in);

    char *st = ans;
    char *en = ans;
    bool str = false, ch = false;
    bool s = false, m = false;

    while (*st != '\0')
    {

        if (str)
        {
            *en = *st;
            en++;
            if (*st == '"')
                str = false;
            st++;
            continue;
        }

        if (ch)
        {
            *en = *st;
            en++;
            if (*st == '\'')
                ch = false;
            st++;
            continue;
        }

        if (s)
        {
            if (*st == '\n')
            {
                s = false;
                *en = *st;
                en++;
            }
            st++;
            continue;
        }

        if (m)
        {
            if (*st == '*' && *(st + 1) == '/')
            {
                m = false;
                st += 2;
            }
            else
            {
                st++;
            }
            continue;
        }

        if (*st == '"')
        {
            str = true;
            *en = *st;
            en++;
            st++;
            continue;
        }

        if (*st == '\'')
        {
            ch = true;
            *en = *st;
            st++;
            en++;
            continue;
        }

        if (*st == '/' && (*(st + 1) == '/' || *(st + 1) == '*'))
        {
            if (*(st + 1) == '/')
            {
                s = true;
            }
            else
            {
                m = true;
            }
            st += 2;
            continue;
        }

        *en = *st;
        st++;
        en++;
    }

    *en = '\0';

    fputs(ans, out);
    fclose(out);

    return 0;
}
