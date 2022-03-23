#include "palindrome.h"

/**
 * is_palindrome - checks if a number is a palindrome
 * @n: input number
 * Return: 1 if true, else 0
 */
int is_palindrome(unsigned long n)
{
	unsigned __int128 div = 1;
	unsigned __int128 mul = 1;

	while (n / div)
		div *= 10;

	while (div >= 10)
	{
		div /= 10;
		if (n / div % 10 != n / mul % 10)
			return (0);
		mul *= 10;
	}

	return (1);
}
