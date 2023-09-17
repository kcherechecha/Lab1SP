#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 30

int main () {
    FILE *fp;
    char word[MAX_WORD_LENGTH + 1];
    char vowels[] = "aeiou";
    char filePath[200]= "/Users/kcherechecha/CLionProjects/Lab1SP/";
    char fileName[100];

    printf("Введіть назву файлу: ");
    scanf("%s", fileName);
    strcat(filePath, fileName);

    fp = fopen(filePath, "r");
    if (fp == NULL) {
        printf("Не вдалося відкрити файл");
        return 1;
    }

    printf("Слова, які складаються лише з голосних літер:\n");
    while (fscanf(fp, "%s", word) != EOF) {
        int vowelOnlyWord = 1;
        for (int i = 0; i < strlen(word); i++) {
            if (!isalpha(word[i]) || !strchr(vowels, word[i])) {
                vowelOnlyWord = 0;
                break;
            }
        }
        if (vowelOnlyWord) {
            printf("%s\n", word);
        }
    }

    fclose(fp);
    return 0;
}