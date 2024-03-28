
#ifndef FONCTION_H
#define FONCTION_H
 
#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 6000
 
int loadWordsFromFile(const char *filename, char **words);
void filterWords(char **words, int numWords, const char *lettersToFilter);
 
#endif /* FONCTION_H */
