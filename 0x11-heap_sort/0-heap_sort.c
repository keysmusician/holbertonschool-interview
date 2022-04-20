#include "sort.h"

/**
 * heap_sort - Sort an array of integers in ascending order using the Heap Sort
 * algorithm
 *
 * @array: Array of integers to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t left_child, right_child, heap_size = size;
	int temp, heap_index, largest;

	while (heap_size > 0)
	{
		heap_index = heap_size / 2 - 1;
		/* Convert the array to a max heap */
		for (; heap_index >= 0; heap_index--)
		{
			largest = heap_index;
			left_child = heap_index * 2 + 1;
			if (left_child < heap_size && array[left_child] > array[largest])
				largest = left_child;
			right_child = heap_index * 2 + 2;
			if (right_child < heap_size && array[right_child] > array[largest])
				largest = right_child;

			if (largest != heap_index)
			{
				temp = array[heap_index];
				array[heap_index] = array[largest];
				array[largest] = temp;
				print_array(array, size);
			}
		}
		/* Swap the root with the end of the array, and decrement heap size */
		if (array[0] != array[heap_size - 1])
		{
			temp = array[0];
			array[0] = array[heap_size - 1];
			array[heap_size - 1] = temp;
			print_array(array, size);
		}
		--heap_size;
	}
}
