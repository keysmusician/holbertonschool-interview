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
	index p = 0, s = -1, t;
	boolean zero_or_more = FALSE;
	char match = '\0', terminal = '\0';

	while (str[++s])
	{
		while (pattern[p] == '*')
			p++;
		match = pattern[p];
		if (match && pattern[p + 1] == '*')
		{
			zero_or_more = TRUE;
			t = p + 1;
			while (pattern[t] == '*')
				t++;
			terminal = pattern[t];
		}
		else
			zero_or_more = FALSE;
		if (zero_or_more)
		{
			if (str[s] == terminal)
				s--;
			else if (match == '.' || str[s] == match)
				continue;
			else
				s--;
		}
		else if (match != '.' && str[s] != match)
			return (FALSE);
		p++;
	}
	return (TRUE);
}
