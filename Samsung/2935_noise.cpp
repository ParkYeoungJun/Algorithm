#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char c1[105], c2[105];

int main()
{
    char ac;

    scanf("%s\n", c1);

    int len1 = strlen(c1);

    scanf("%c\n", &ac);

    scanf("%s\n", c2);

    int len2 = strlen(c2);

    if (ac == '*')
    {
        printf("1");

        for (int i = 2; i < len1 + len2; ++i)
        {
            printf("0");
        }
    }
    else
    {
        if (len1 == 1 && len2 == 1)
        {
            printf("2");
        }
        else if(len1 == len2)
        {
            printf("2");

            for(int i = 1 ; i < len1 ; ++i)
                printf("0");
        }
        else
        {
            printf("1");

            int more = max(len1, len2);
            int less = min(len1, len2);

            for (int i = 1; i < more - less; ++i)
            {
                printf("0");
            }

            printf("1");

            for (int i = 1; i < less; ++i)
            {
                printf("0");
            }
        }
    }
}