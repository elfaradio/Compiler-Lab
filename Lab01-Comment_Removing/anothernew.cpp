#include <iostream>
#include <string>
using namespace std;

string removeComments(const string &src)
{
    const char *p = src.c_str();
    string dest;

    while (*p != '\0')
    {

        if (*p == '/' && *(p + 1) == '/')
        {
            p += 2;
            while (*p != '\n' && *p != '\0')
                p++;
        }

        else if (*p == '/' && *(p + 1) == '*')
        {
            p += 2;
            while (!(*p == '*' && *(p + 1) == '/') && *p != '\0')
                p++;
            if (*p != '\0')
                p += 2;
        }
        else
        {
            dest += *p;
            p++;
        }
    }

    return dest;
}

int main()
{
    string code = R"(int a = 5; /* remove this */ int b = 10; // single line comment
printf("%d", a + b); /* another
multi-line
comment */)";

    string result = removeComments(code);
    cout << result << endl;

    return 0;
}
