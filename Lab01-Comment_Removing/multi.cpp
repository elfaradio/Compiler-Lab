#include <stdio.h>

void solve(char *src, char *dest)
{
    while (*src != '\0')
    {
        if (*src == '/' && *(src + 1) == '*')
        {
            src += 2;
            while (!(*src == '*' && *(src + 1) == '/') && *src != '\0')
                src++;
            if (*src != '\0')
                src += 2;
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
    char code[] = "int a=5; /* remove this */ int b=10;";
    char ans[200];
    solve(code, ans);
    printf("%s\n", ans);
    return 0;
}
