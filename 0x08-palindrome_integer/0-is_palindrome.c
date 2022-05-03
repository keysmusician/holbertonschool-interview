#include "palindrome.h"

/**
 * is_palindrome - checks if a number is a palindrome
 * @n: input number
 * Return: 1 if true, else 0
 */
int is_palindrome(unsigned long n)
{
	unsigned long div = 1;
	unsigned long mul = 1;

	while (n / div / 10 > 0)
		div *= 10;

	while (div)
	{
		if (n / div % 10 != n / mul % 10)
			return (0);
		div /= 10;
		mul *= 10;
	}

	return (1);
}
