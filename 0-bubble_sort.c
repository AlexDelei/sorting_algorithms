#include "sort.h"
/**
 *swap - swaps two elements
 *@a:the first number
 *@b:the second number
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 *bubble_sort - sorting algorithm
 *@array: input array
 *@size:size of our array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, k;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);

				for (k = 0; k < size; k++)
				{
					printf("%d", array[k]);
					if (k < size - 1)
					{
						printf(", ");
					}
				}
				printf("\n");
			}
		}
	}
}
