#include<stdio.h>
#include<string.h>

int is_alphabet(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main()
{
    char sentence[201];
    fgets(sentence, 201, stdin);

    sentence[strcspn(sentence, "\n")] = '\0';

    int words = 0;
    int len = strlen(sentence);

    for(int i = 0; i < len; i++)
    {
        if(is_alphabet(sentence[i]) && (i == 0 || !is_alphabet(sentence[i - 1])))
        {
            words++;
        }
    }

    printf("单词数量: %d\n", words);
    return 0;
}