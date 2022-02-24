#include <stdlib.h>
#include <stdio.h>

#include "slide_line.h"

/**
 * move_zeros_to_left - move zeros to the left
 * @line: Pointer to an array of integers
 * containing size elements
 * @size: Number of elements in @array
 */
void move_zeros_to_left(int *line, int size)
{
	int write_index = size - 1;
	int read_index = size - 1;

	if (size < 1)
		return;
	while (read_index >= 0)
	{
		if (line[read_index] != 0)
		{
			line[write_index] = line[read_index];
			write_index--;
		}

		read_index--;
	}
	while (write_index >= 0)
	{
		line[write_index] = 0;
		write_index--;
	}
}
/**
 * move_zeros_to_right - move zeros to the right
 * @line: Pointer to an array of integers
 * containing size elements
 * @size: Number of elements in @array
 */
void move_zeros_to_right(int *line, int size)
{
	int write_index = 0;
	int read_index = 0;

	if (size < 1)
		return;
	while (read_index < size)
	{
		if (line[read_index] != 0)
		{
			line[write_index] = line[read_index];
			write_index++;
		}
		read_index++;
	}
	while (write_index < size)
	{
		line[write_index] = 0;
		write_index++;
	}

}
/**
 * merge_left - merge numbers to the left
 * @line: Pointer to an array of integers
 * containing size elements
 * @size: Number of elements in @array
 */
void merge_left(int *line, size_t size)
{
	size_t i, j;

	i = 0;
	while (i < size)
	{
		while (line[i] == 0)
			i++;
		j = i + 1;
		while (line[j] == 0)
			j++;
		if (line[i] == line[j])
		{
			line[i] = line[i] + line[j];
			line[j] = 0;
			i = j + 1;
		}
		else if (line[i] != line[j])
		{
			i = j;
		}
	}
}

/**
 * slide_line -  slides and merges an array of integers
 *
 * @line: Pointer to an array of integers
 * containing size elements
 * @size: Number of elements in @array
 * @direction: slided & merged to the direction
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i, j;

	if (direction == 1)
	{
		/* Merge to left */
		merge_left(line, size);
		move_zeros_to_right(line, size);
		return (1);
	}
	else
	{
		i = size - 1;
		while (i > 0)
		{
			while (line[i] == 0)
				i--;
			j = i - 1;
			while (line[j] == 0)
			{
				if (j == 0)
					break;
				j--;
			}
			if (line[i] == line[j])
			{
				line[i] = line[i] + line[j];
				line[j] = 0;
				if (j != 0)
					i = j - 1;
			}
			else
			{
				i = j;
			}
		}
		move_zeros_to_left(line, size);
		return (1);
	}
	return (0);
}
