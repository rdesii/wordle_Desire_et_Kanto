#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"
 
int main() {
    char *words[MAX_NUM_WORDS];
    int numWords;
 
    // Charger les mots à partir du fichier
    numWords = loadWordsFromFile("/home/desire/wordle_Desire_et_Kanto/ressource/bdd_wordle.txt", words);
 
    char lettersToFilter[MAX_WORD_LENGTH];
    printf("Entrez les lettres à filtrer : ");
    scanf("%s", lettersToFilter);
 
    // Filtrer les mots en fonction des lettres saisies par l'utilisateur
    filterWords(words, numWords, lettersToFilter);
 
    // Libérer la mémoire allouée pour les mots
    for (int i = 0; i < numWords; i++) {
        free(words[i]);
    }
 
    return 0;
}
