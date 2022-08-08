#include "regex.h"

/**
 * regex_match - Checks whether a given pattern matches a given string
 *
 * @str: A string (cannot contain '.' or '*')
 * @pattern: A regular expression (supports '.' and '*')
 *
 * Return: TRUE if the pattern matches the string, FALSE otherwise
 */
int regex_match(char const *str, char const *pattern)
{
	index p = 0, s = 0;
	char pattern_prev = '\0';

	for (; str[s] || pattern[s]; s++, p++)
	{
		if (pattern[p] != '.')
		{
			if (pattern[p] == '*' &&
				(pattern_prev == '.' || str[p] == pattern_prev)
			)
			{
				p--;
				continue;
			}
			if (str[s] != pattern[s])
				return (FALSE);
		}

		pattern_prev = pattern[p];
	}

	return (TRUE);
}
