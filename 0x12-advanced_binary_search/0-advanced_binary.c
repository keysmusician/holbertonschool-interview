#include "search_algos.h"

/**
 * advanced_binary - searches for a value in a sorted array of integers,
 * returning the index of the first match if the value appears more than once.
 *
 * @array: a pointer to the first element of the array to search in
 * @size: the number of elements in `array`
 * @value: the value to search for
 *
 * Return: the index of the first matching value
 */
int advanced_binary(int *array, size_t size, int value)
{
	static size_t offset;
	size_t i, mid, temp;

	if (size < 1)
	{
		offset = 0;
		return (-1);
	}
	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
	mid = (size + 1) / 2;
	if (mid > 0)
	{
		if (value > array[size / 2])
		{
			offset += mid;
			return (advanced_binary(array + mid, size - mid, value));
		}
		else if (value == array[0])
		{
			temp = offset;
			offset = 0;
			return (temp);
		}
		else
			return (advanced_binary(array, size - mid, value));
	}
	else
		offset = 0;
	return (-1);
}
