#include<stdio.h>
#include<string.h>

int is_vowels(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int is_consonants(char c)
{
    if(is_vowels(c)) return 0;
    else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return 1;
    else return 0;
}

int main()
{
    char str[1001];
    fgets(str, 1001, stdin);

    int vowels = 0, consonants = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (is_vowels(str[i])) vowels++;
        else if (is_consonants(str[i])) consonants++;
    }

    printf("元音字母数量：%d\n辅音字母数量: %d\n", vowels, consonants);
}