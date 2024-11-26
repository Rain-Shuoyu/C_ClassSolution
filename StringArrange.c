#include <stdio.h>
#include <string.h>
#include<stdlib.h>

#define MAX_PERMUTATIONS 120

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *str, int l, int r, char result[MAX_PERMUTATIONS][6], int *index) {
    if (l == r) {
        strcpy(result[*index], str);
        (*index)++;
    } else {
        for (int i = l; i <= r; i++) {
            swap((str + l), (str + i));
            permute(str, l + 1, r, result, index);
            swap((str + l), (str + i)); 
        }
    }
}

int compare(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

int main() {
    char str[6]; 
    scanf("%s", str);

    int len = strlen(str);
    char result[MAX_PERMUTATIONS][6]; 
    int index = 0;

    permute(str, 0, len - 1, result, &index);

    qsort(result, index, sizeof(result[0]), compare);

    for (int i = 0; i < index; i++) {
        if (i == 0 || strcmp(result[i], result[i - 1]) != 0) {
            printf("%s\n", result[i]);
        }
    }

    return 0;
}