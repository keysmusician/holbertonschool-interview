#include "regex.h"

#if DEBUG
#include <stdio.h>
#endif

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
	boolean zero_or_more = FALSE; /* Tracks use of the '*' modifier. Might be unnecessary to store as a bool. */
	char match = '\0', terminal = '\0';

	while (str[++s])
	{
		/* Find the character class to match against (in this case, a character
		class will only contain a single character). We can always skip over
		modifiers, as they don't represent character classes. The only modifier
		in this task is '*'. */
		while (pattern[p] == '*')
			p++;

		match = pattern[p];

#if DEBUG
		printf("char = %c\n", str[s]);
		printf("match = %c\n", match);
#endif

		/* Check if the character class is modified. There will only be one
		modifier: '*'. If there's an '*' after the character class, it's
		modified. */
		if (match && pattern[p + 1] == '*')
		{
			zero_or_more = TRUE;

			/* Find the terminal character. If a character class is modified,
			we need to know what the terminal character class is. */
			/* This is redundant code. */
			t = p + 1;
			while (pattern[t] == '*')
				t++;

			terminal = pattern[t];
		}
		else
			/* We shouldn't have to change the terminal character class here
			because we should ignore it. */
			zero_or_more = FALSE;



		/* Check if the current character class is modified. */
		if (zero_or_more)
		{
#if DEBUG
			printf("terminal = %c\n", terminal);
#endif
			/* Check if the current character matches the terminal character
			class. */
			if (str[s] == terminal)
			{
				/* Stay on the current charater, but set the terminal character
				class to the active one and recheck. */
				s--;
				p++;
				continue;
			}
			/* (Else,) check if the current character matches the active
			character class. */
			if (match == '.' || str[s] == match)
			{
				/* Check the next character, but don't change the active
				character class */
				continue;
			}
			else
			{ /* Redundant */
				/* Stay on the current charater, but set the terminal character
				class to the active one and recheck. */
				s--;
				p++;
				continue;
			}

		} /* DO NOT use `terminal` beyond this point */
		/* If the current character class is not modified: */
		else if (match != '.' && str[s] != match)
				return (FALSE);
		p++;
	}

	return (TRUE);
}
