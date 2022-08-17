#ifndef SUBSTRING_H
#define SUBSTRING_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TRUE (char)1
#define FALSE 0

typedef int index_t;
typedef char *boolean_list;
typedef char boolean;

int *find_substring(char const *s, char const **words, int nb_words, int *n);

#endif /* SUBSTRING_H */
