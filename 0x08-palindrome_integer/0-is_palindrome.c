/**
 * is_palindrome - Checks whether or not a given unsigned integer is a
 * palindrome
 *
 * @n: A positive integer <= 9,223,372,036,854,775,807.
 *
 * Return: 1 if n is a palindrome, 0 otherwise.
 */
int is_palindrome(unsigned long n)
{
	unsigned long div = 1;
	unsigned long mul = 1;

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
