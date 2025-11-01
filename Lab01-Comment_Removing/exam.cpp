#include <bits/stdc++.h>
using namespace std;
int main()
{

    FILE *in = fopen("a.c", "r");
    FILE *out = fopen("output.c", "w");
    if (!in or !out)
    {
        cout << "Not a file";
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
    bool str = false, ch = false, s = false, m = false;
    while (*st != '\0')
    {
        if (str)
        {
            fputc(*st, out);
            if (*st == '"')
            {
                str = false;
            }
            st++;
            continue;
        }
        if (ch)
        {
            fputc(*st, out);
            if (*st == '\'')
            {
                ch = false;
            }
            st++;
            continue;
        }
        if (s)
        {
            if (*st == '\n')
            {
                fputc(*st, out);
                s = false;
            }
            st++;
            continue;
        }
        if (m)
        {
            if (*st == '*' and *(st + 1) == '/')
            {
                m = false;
                st += 2;
            }
            st++;
            continue;
        }
        if (*st == '"')
        {
            str = true;
            fputc(*st, out);
            st++;
            continue;
        }
        if (*st == '\'')
        {
            ch = true;
            fputc(*st, out);
            st += 1;
            continue;
        }
        if (*st == '/' and *(st + 1) != '\0')
        {
            if (*(st + 1) == '/')
            {
                s = true;
                st += 2;
                continue;
            }
            if (*(st + 1) == '*')
            {
                m = true;
                st += 2;
                continue;
            }
        }
        fputc(*st, out);
        st++;
    }
    fclose(out);
}