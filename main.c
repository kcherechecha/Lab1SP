#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main () {
    FILE *fp;
    char word[31];
    char vowels[] = "aeiou";
    char filePath[200]= "/Users/kcherechecha/CLionProjects/Lab1SP/";
    char fileName[100];
    int wordCount = 0;
    char uniqueWords[1000][31];

    printf("Введіть назву файлу: ");
    scanf("%s", fileName);
    strcat(filePath, fileName);

    fp = fopen(filePath, "r");
    if (fp == NULL) {
        printf("Не вдалося відкрити файл");
        return 0;
    }

    printf("Слова, які складаються лише з голосних літер:\n");
    while (fscanf(fp, "%s", word) != EOF) {
        if (strlen(word) <= 30) {
            int vowelOnlyWord = 1;
            for (int i = 0; i < strlen(word); i++) {
                if (!isalpha(word[i]) || !strchr(vowels, word[i])) {
                    vowelOnlyWord = 0;
                    break;
                }
            }
            if (vowelOnlyWord) {
                int duplicate = 0;
                for (int i = 0; i < wordCount ; i++) {
                    if (strcmp(uniqueWords[i], word) == 0)  {
                        duplicate = 1;
                    }
                }
                if(duplicate != 1)
                    printf("%s\n", word);
                strcpy(uniqueWords[wordCount], word);
                wordCount++;
            }
        }
    }

    fclose(fp);
    return 0;
}