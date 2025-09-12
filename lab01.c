#include <stdio.h>

int main()
{
    FILE *in, *out;
    in = fopen("a.c", "r");
    out = fopen("output.c", "w");

    if (in == NULL || out == NULL)
    {
        printf("Cannot Open File\n");
        return 0;
    }

    int ch, x;
    while ((ch = fgetc(in)) != EOF)
    {
        if (ch == '/')
        {
            x = fgetc(in);
            if (x == '/')
            {
                while ((ch = fgetc(in)) != EOF && ch != '\n')
                    fputc('\n', out);
            }
            else if (x == '*')
            {
                while ((ch = fgetc(in)) != EOF)
                {
                    if (ch == '*')
                    {
                        x = fgetc(in);
                        if (x == '/')
                            break;
                    }
                }
            }
            else
            {
                fputc('/', out);
                if (x != EOF)
                    fputc(x, out);
            }
        }
        else
        {
            fputc(ch, out);
        }
    }

    fclose(in);
    fclose(out);
    return 0;
}
