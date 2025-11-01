#include <bits/stdc++.h>
using namespace std;

int main()
{
    FILE *in = fopen("a.c", "r");
    FILE *out = fopen("output.c", "w");

    if (!in || !out)
        return 1;

    char ans[10000];
    char *st = ans;
    int c;

    char *x = ans;
    while ((c = fgetc(in)) != EOF)
    {
        *x++ = c;
    }
    *x = '\0';
    fclose(in);

    while (*st != '\0')
    {

        if (*st == '/' && *(st + 1) != '\0' && *(st + 1) == '/')
        {
            st += 2;
            while (*st != '\n' && *st != '\0')
                st++;
            continue;
        }

        if (*st == '/' && *(st + 1) != '\0' && *(st + 1) == '*')
        {
            st += 2;
            while (!(*st == '*' && *(st + 1) != '\0' && *(st + 1) == '/') && *st != '\0')
                st++;
            if (*st != '\0')
                st += 2;
            continue;
        }

        fputc(*st++, out);
    }

    fclose(out);

    return 0;
}
