#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char num1[200], num2[200];
    int result[1024] = {0};
    scanf ("%s %s", num1, num2);
    int len1 = strlen(num1), len2 = strlen(num2);

    int i, j;

    for(i =len1 -1; i >= 0 ; i--)
    {
        for(j = len2 - 1; j >= 0; j--)
        {
            result[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
        }
    }

    for(i = len1 + len2 - 1; i > 0; i--)
    {
        if(result[i] > 9)
        {
            result[i - 1] += result[i] / 10;
            result[i] %= 10;
        }
    }

    int start = 0;
    while(start < len1 + len2 && result[start] == 0)
        start++;

    if(start == len1 + len2)
        printf("0\n");
    else
    {
        for(i = start; i < len1 + len2; i++)
            printf("%d", result[i]);
        printf("\n");
    }

    return 0;
}