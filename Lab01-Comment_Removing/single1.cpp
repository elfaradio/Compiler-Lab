#include <stdio.h>

void ans(char *src, char *dest)
{
    while (*src != '\0')
    {
        if (*src == '/' && *(src + 1) == '/')
        {
            while (*src != '\n' && *src != '\0')
                src++;
        }
        else
        {
            *dest++ = *src++;
        }
    }
    *dest = '\0';
}

int main()
{
    char code[] = "int x=10; // this is a comment\nprintf(\"%d\", x);";
    char ANS[200];
    ans(code, ANS);
    printf("%s\n", ANS);
    return 0;
}
