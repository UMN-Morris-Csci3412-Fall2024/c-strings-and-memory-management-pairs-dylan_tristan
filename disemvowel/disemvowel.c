#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "disemvowel.h"

// function to fnd out if input character is a vowel
int is_vowel(char c) {
    char lower_c = tolower(c);
    return lower_c == 'a' || lower_c == 'e' || lower_c == 'i' || lower_c == 'o' || lower_c == 'u';
}

char *disemvowel(char *str) {
  int length = strlen(str);
  int count = 0;

  //Count Non-Vowel Character
  for (int i = 0; i < length; i++) {
    if (!is_vowel(str[i])) {
      count++;
    }
  }

  //Allocate Memory for new string based on non-vowel characters + 1
  char *result = (char *)malloc((count + 1) * sizeof(char));
  // if (result == NULL) {
  //   return NULL;
  // }

  //Copy non-vowel characters
  int j = 0;
    for (int i = 0; i < length; i++) {
        if (!is_vowel(str[i])) {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';
    
  // Return new string
  return result;

  //return (char*) "";
}
