#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int loadWordsFromFile(const char *filename, char **words) {
    FILE *file = fopen(filename, "r");
    int numWords = 0;
    char word[MAX_WORD_LENGTH];
 
    // Lire chaque mot du fichier et les stocker dans la liste
    while (fscanf(file, "%s", word) != EOF) {
        words[numWords] = malloc(strlen(word) + 1);
        strcpy(words[numWords], word);
        numWords++;
    }
 
    fclose(file);
    return numWords;
}
 
void filterWords(char **words, int numWords, const char *lettersToFilter) {
    printf("Mots filtrés :\n");
    char filteredWords[MAX_NUM_WORDS * MAX_WORD_LENGTH] = ""; // Chaîne pour stocker les mots filtrés
    for (int i = 0; i < numWords; i++) {
        int containsAllLetters = 1;
        int len = strlen(lettersToFilter);
        for (int j = 0; j < len; j++) {
            if (strchr(words[i], lettersToFilter[j]) == NULL) {
                containsAllLetters = 0;
                break;
            }
        }
        if (containsAllLetters) {
            strcat(filteredWords, words[i]);
            strcat(filteredWords, " "); // Ajouter un espace entre les mots
        }
    }
    printf("%s\n", filteredWords); // Afficher les mots filtrés
}
