#include "sort.h"

#define DIGIT_COUNT 10
#define TRUE 1
#define FALSE 0


/**
 * radix_sort - Sorts an array of positive integers in ascending order using
 * the Radix sort algorithm
 *
 * @array: Array to sort
 * @size: Size of `array`
 */
void radix_sort(int *array, size_t size)
{
	long digit_place = 1;
	int histogram[DIGIT_COUNT] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;
	int digit, *array_copy = NULL;
	char increase_digit_place = TRUE;

	array_copy = (int *)malloc(sizeof(int) * size);
	if (!array_copy)
		return;

	while (increase_digit_place)
	{
		increase_digit_place = FALSE;
		for (i = 0; i < size; i++)
		{
			array_copy[i] = array[i]; /* Copy the array */
			if (array[i] / digit_place > 0)
				increase_digit_place = TRUE;
			digit = array[i] / digit_place % DIGIT_COUNT;
			histogram[digit]++; /* Count occurrences of each digit */
		}
		if (!increase_digit_place)
			break; /* If all digits less than digit_place, we're done */
		for (i = 1; i < DIGIT_COUNT; i++)
			histogram[i] += histogram[i - 1]; /* Convert counts to indicies */

		for (i = size - 1; ; i--)
		{
			digit = array_copy[i] / digit_place % DIGIT_COUNT;
			histogram[digit]--;
			array[histogram[digit]] = array_copy[i];
			if (i == 0)
				break;
		}
		print_array(array, size);
		digit_place *= DIGIT_COUNT;
		for (i = 0; i < DIGIT_COUNT; i++) /* Reset histogram */
			histogram[i] = 0;
	}
	free(array_copy);
}
