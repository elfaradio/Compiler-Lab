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

    int c, nxt;
    bool STRING = false, CHAR = false, single = false, multi = false;

    while ((c = fgetc(in)) != EOF)
    {

        // Str op
        if (STRING)
        {
            fputc(c, out);
            if (c == '"')
                STRING = false;
            continue;
        }

        // Char Op
        if (CHAR)
        {
            fputc(c, out);
            if (c == '\'')
                CHAR = false;
            continue;
        }

        // Single comment
        if (single)
        {
            if (c == '\n')
            {
                single = false;
                fputc(c, out);
            }
            continue;
        }

        // Multiline Comment
        if (multi)
        {
            if (c == '*' && (nxt = fgetc(in)) != EOF)
            {
                if (nxt == '/')
                    multi = false;
            }
            continue;
        }

        // Str Start
        if (c == '"')
        {
            STRING = true;
            fputc(c, out);
            continue;
        }

        // char start
        if (c == '\'')
        {
            CHAR = true;
            fputc(c, out);
            continue;
        }

        // For Comments
        if (c == '/' && (nxt = fgetc(in)) != EOF)
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
    return 0;
}
