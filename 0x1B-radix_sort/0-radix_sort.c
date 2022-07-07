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
	int histogram[DIGIT_COUNT], digit, digit_place, *array_copy = NULL;
	char increase_digit_place;
	size_t i;

	array_copy = (int *)malloc(sizeof(int) * size);
	if (!array_copy)
		return;

	for (digit_place = 1; ; digit_place *= DIGIT_COUNT)
	{
		increase_digit_place = FALSE; /* Assume this will be our final loop */

		for (i = 0; i < DIGIT_COUNT; i++) /* Clear the histogram */
			histogram[i] = 0;

		for (i = 0; i < size; i++)
		{
			array_copy[i] = array[i]; /* Copy the array */
			if (array[i] / digit_place > 0) /* Check if we need to loop */
				increase_digit_place = TRUE;
			digit = array[i] / digit_place % DIGIT_COUNT;
			histogram[digit]++; /* Count occurrences of each digit */
		}
		if (!increase_digit_place)
			break; /* If all digits are less than digit_place, we're done */

		for (i = 1; i < DIGIT_COUNT; i++)
			histogram[i] += histogram[i - 1]; /* Convert counts to indicies */

		i = size - 1;
		do { /* Sort the array by digit */
			digit = array_copy[i] / digit_place % DIGIT_COUNT;
			histogram[digit]--;
			array[histogram[digit]] = array_copy[i];
		} while (i-- > 0);

		print_array(array, size);
	}
	free(array_copy);
}
