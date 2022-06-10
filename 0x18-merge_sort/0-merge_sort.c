#include "sort.h"

/**
 * TopDownMerge - Merge runs into sorted runs
 *
 * Left source half is A[iBegin:iMiddle-1].
 * Right source half is A[iMiddle:iEnd-1].
 * Result is B[iBegin:iEnd-1].
 *
 * @source: source array to sort
 * @iBegin: start index of the left split in a run
 * @iMiddle: start index of the right split in a run
 * @iEnd: end index of the run
 * @dest: copy of source array
 */
void TopDownMerge(int *source, size_t iBegin, size_t iMiddle, size_t iEnd,
int *dest)
{
	size_t i = iBegin, j = iMiddle, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(source + iBegin, iMiddle - iBegin);
	printf("[right]: ");
	print_array(source + iMiddle, iEnd - iMiddle);
	/* while there are elements in the left or right runs */
	for (k = iBegin; k < iEnd; k++)
	{
		if (i < iMiddle && (j >= iEnd || source[i] <= source[j]))
		{
			dest[k] = source[i];
			i = i + 1;
		}
		else
		{
			dest[k] = source[j];
			j = j + 1;
		}
	}
	printf("[Done]: ");
	print_array(dest + iBegin, iEnd - iBegin);
}

/**
 * TopDownSplitMerge - Split array into 2 runs, sort both runs into array_copy,
 * merge both runs from array_copy to array
 *
 * iBegin is inclusive; iEnd is exclusive (array[iEnd] is not in the set).
 *
 * @array_copy: copy of array
 * @iBegin: start index
 * @iEnd: end index
 * @array: array to sort
 */
void TopDownSplitMerge(int *array_copy, size_t iBegin, size_t iEnd, int *array)
{
	size_t iMiddle;

	if (iEnd - iBegin <= 1)
		return;
	/* split the run longer than 1 item into halves */
	iMiddle = (iEnd + iBegin) / 2;
	/* recursively sort both runs from array A[] into B[] */
	TopDownSplitMerge(array, iBegin, iMiddle, array_copy);
	TopDownSplitMerge(array, iMiddle, iEnd, array_copy);
	/* merge the resulting runs from array_copy into array */
	TopDownMerge(array_copy, iBegin, iMiddle, iEnd, array);
}

/**
 * merge_sort - Sort an array of integers in ascending order using the merge
 * sort algorithm
 *
 * @array: array to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *array_copy = NULL;
	size_t i;

	if (array && size > 0)
	{
		/* copy array */
		array_copy = (int *)malloc(sizeof(int) * size);
		for (i = 0; i < size; i++)
			array_copy[i] = array[i];

		/* sort data from array_copy into array */
		TopDownSplitMerge(array_copy, 0, size, array);
		free(array_copy);
	}
}
