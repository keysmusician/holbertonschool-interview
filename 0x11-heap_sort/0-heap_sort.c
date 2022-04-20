#include "sort.h"

/**
 * heapify - Convert an array to a max heap
 * @array: Array to convert
 * @size: Size of the array
 * @index: Heap starting index
 * @heap_size: Size of the heap
 */
void heapify(int *array, size_t size, int index, size_t heap_size)
{
	int largest = index;
	int left_child = 2 * index + 1;
	int right_child = 2 * index + 2;
	int temp;

	if (left_child < (int)size && array[left_child] > array[largest])
		largest = left_child;
	if (right_child < (int)size && array[right_child] > array[largest])
		largest = right_child;
	if (largest != index)
	{
		temp = array[index];
		array[index] = array[largest];
		array[largest] = temp;
		print_array(array, heap_size);
		heapify(array, size, largest, heap_size);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending order using the Heap Sort
 * algorithm
 *
 * @array: Array of integers to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	int index, temp;

	for (index = (int)size / 2 - 1; index >= 0; index--)
		heapify(array, size, index, size);
	for (index = (int)size - 1; index > 0; index--)
	{
		temp = array[0];
		array[0] = array[index];
		array[index] = temp;
		print_array(array, size);
		heapify(array, (size_t)index, 0, size);
	}
}
