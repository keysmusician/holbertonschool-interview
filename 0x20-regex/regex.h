#ifndef REGEX_H
#define REGEX_H

#define TRUE 1
#define FALSE 0

typedef int index;
typedef char boolean;

int regex_match(char const *str, char const *pattern);

#endif /* REGEX_H */
