#include "search_algos.h"

/**
 * recursion - recursive binary search
 * @array: a pointer to the first element of the array to search in
 * @offset: offset from the beginning of the array
 * @size: the number of elements in `array`
 * @value: the value to search for
 * Return: index where value is stored, else -1
 */
int recursion(int *array, int offset, int size, int value)
{
	int mid, i;

	if (size >= offset)
	{
		printf("Searching in array: ");
		for (i = offset; i <= size; i++)
			printf("%i%s", array[i], i <= size - 1 ? ", " : "\n");

		mid = offset + (size - offset) / 2;
		if (array[mid] == value && array[mid - 1] != value)
			return (mid);
		if (array[mid] >= value)
			return (recursion(array, offset, mid, value));
		return (recursion(array, mid + 1, size, value));
	}
	return (-1);
}

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
	return (recursion(array, 0, size - 1, value));
}
