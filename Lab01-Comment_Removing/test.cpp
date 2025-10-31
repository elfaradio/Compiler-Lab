#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{

    FILE *in = fopen("a.c", "r");
    FILE *out = fopen("output.c", "w");
    if (!in or !out)
    {
        cout << "sorry";
        return 1;
    }
    int c, nxt;
    bool str = false, cha = false, single = false, multi = false;
    while ((c = fgetc(in)) != EOF)
    {
        if (str)
        {
            fputc(c, out);
            if (c == '"')
            {
                str = false;
            }

            continue;
        }
        if (cha)
        {
            fputc(c, out);
            if (c == '\'')
            {
                cha = false;
            }
            continue;
        }
        if (single)
        {

            if (c == '\n')
            {
                single = false;
                fputc(c, out);
            }
            continue;
        }
        if (multi)
        {
            if (c == '*' and (nxt = fgetc(in)) != EOF)
            {
                if (nxt == '/')
                {
                    multi = false;
                }
            }
            continue;
        }
        if (c == '"')
        {
            str = true;
            fputc(c, out);
            continue;
        }
        if (c == '\'')
        {
            cha = true;
            fputc(c, out);
            continue;
        }
        if (c == '/' and (nxt = fgetc(in)) != EOF)
        {
            if (nxt == '/')
            {
                single = true;
                continue;
            }
            else if (nxt == '*')
            {
                multi = true;
                continue;
            }
            else
            {
                fputc(c, out);
                fputc(nxt, out);
                continue;
            }
        }
        fputc(c, out);
    }
    fclose(in);
    fclose(out);
}