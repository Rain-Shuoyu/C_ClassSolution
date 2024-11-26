#include <stdio.h>
#include <string.h>

int main()
{
    char str1[200], str2[200], str_return[200];
    int max_len = 0;
    scanf("%s %s", str1, str2);
    int len1 = strlen(str1), len2 = strlen(str2);

    for(int i = 0; i < len1; i++)
    {
        for(int j = i; j < len1; j++)
        {
            for(int k = 0; k <= len2 - (j - i + 1); k++)
            {
                if(strncmp(&str2[k], &str1[i], j - i + 1) == 0 && j - i + 1 > max_len)
                {
                    max_len = j - i + 1;
                    strncpy(str_return, &str2[k], j - i + 1);
                    str_return[j - i + 1] = '\0';
                }
            }
        }
    }

    if(max_len == 0)
    {
        printf("没有公共子串");
    }
    else
    {
        printf("%s\n", str_return);
    }
    return 0;
}