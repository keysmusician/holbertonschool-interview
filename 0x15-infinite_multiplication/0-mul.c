#include "holberton.h"

/**
 * is_number - Validates that a string is numeric
 *
 * @string: A string
 *
 * Return: 1 if valid, 0 if invalid
 */
int is_number(char *string)
{
	int i;
	char c;

	for (i = 0; string[i]; i++)
	{
		c = string[i];
		if (c < '0' || c > '9')
			return (0);
	}

	return (1);
}

/**
 * print_string - Prints a string
 *
 * @string: A string
 */
void print_string(char *string)
{
	int i;

	for (i = 0; string[i]; i++)
		_putchar(string[i]);
	_putchar('\n');
}

/**
 * _strlen - Calculates the length of a string
 *
 * @str: A string
 *
 * Return: The length of the string
 */
size_t _strlen(char *str) { return (str[0] ? 1 + _strlen(str + 1) : 0); }

/**
 * main - Multiplies two arbitrarily large integers and prints the result
 *
 * @argc: Command line argument count
 * @argv: Command line arguments
 *
 * Return: EXIT_SUCCESS on success, 98 on failure.
 */
int main(int argc, char **argv)
{
	char *a, *b, digit_a, digit_b, sum;
	char *result;
	int i = 0, j, k;
	size_t result_length, a_length, b_length;

	if (argc != 3 || !is_number(argv[1]) || !is_number(argv[2]))
	{
		print_string("Error");
		exit(98);
	}

	a = argv[1];
	b = argv[2];
	a_length = _strlen(a);
	b_length = _strlen(b);
	result_length = a_length + b_length;

	result = (char *)malloc(result_length);
	while ((size_t)i < result_length)
		result[i++] = 0;

	for (i = a_length - 1; i >= 0; i--)
	{
		digit_a = a[i] - '0';
		for (j = b_length - 1; j >= 0; j--)
		{
			digit_b = b[j] - '0';
			k = result_length - 1 - (b_length - 1 - j) - (a_length - 1 - i);
			result[k] += digit_a * digit_b;
			for (sum = result[k]; sum > 9; sum = result[k])
			{
				result[k--] = sum % 10;
				result[k] += sum / 10;
			}
		}
	}
	for (i = k; (size_t)i < result_length; i++)
		result[i] += '0';

	print_string(result + k);
	free(result);

	return (EXIT_SUCCESS);
}
