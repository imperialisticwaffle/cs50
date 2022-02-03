// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45   // clang will replace any mentions of LENGTH in your own code with, literally, 45. In other words, it’s not a variable, just a find-and-replace trick.

// Prototypes
bool check(const char *word);       // Takes string
unsigned int hash(const char *word);    // ^
bool load(const char *dictionary);      // ^
unsigned int size(void);
bool unload(void);

#endif // DICTIONARY_H
