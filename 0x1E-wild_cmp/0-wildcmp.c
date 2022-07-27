#include "holberton.h"

/**
 * not_asterisk - Finds the first character that is not an asterisk in a
 * string.
 *
 * @s: A string.
 * Return: Pointer to the first non-asterisk character in the string.
 */
char *not_asterisk(char *s)
{
	if (s[0] == '*')
		return (not_asterisk(s + 1));
	return (s);
}

/**
 * find_char - Finds the first occurrence of a character in a string.
 *
 * @s: A string.
 * @c: A character.
 *
 * Return: The position of the character in the string, or NULL.
 */
char *find_char(char *s, char c)
{
	if (s[0] == c)
		return (s);
	if (s[0] == '\0')
		return (NULL);
	return (find_char(s + 1, c));
}

/**
 * wildcmp - Determines whether two strings may be considered identical.
 *
 * @s1: String 1.
 * @s2: String 2 (may include wildcard character "*").
 *
 * Return: TRUE if the strings compare equal, FALSE otherwise.
 */
int wildcmp(char *s1, char *s2)
{
	char *s3;

	if (!s1 || !s2)
		return (FALSE);
	if (s2[0] == '*')
	{
		s3 = not_asterisk(s2);

		s1 = find_char(s1, s3[0]);
		if (!s1)
			return (FALSE);

		if (wildcmp(s1, s3) == FALSE)
			return (wildcmp(s1 + 1, s2));
		else
			return (TRUE);
	}
	if (s1[0] != s2[0]) /* Characters are not equal */
		return (FALSE);
	if (!s1[0]) /* Characters are equal and string is complete */
		return (TRUE);
	else /* Characters are equal and string is incomplete */
		return (wildcmp(s1 + 1, s2 + 1));
}
