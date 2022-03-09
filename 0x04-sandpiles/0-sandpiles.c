#include "sandpiles.h"
/**
 * stable - check if a sandpile is stable or unstable
 * @arr: 3x3 grid
 * Return: 0 if arr is unstable, 1 if arr is stable.
 */
int stable(int arr[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (arr[i][j] > 3)
				return (0);
	return (1); }
/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n"); }
}
/**
 * copy_result - copy result from arr_from to arr_to
 * @arr_from: 3x3 grid
 * @arr_to: 3x3 grid
 */
void copy_result(int arr_from[3][3], int arr_to[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			arr_to[i][j] = arr_from[i][j]; }
/**
 * new_grid - making new grid
 * @grid: 3x3 grid (all zeros)
 */
void new_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid[i][j] = 0; }
/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: Left 3x3 grid  and Result
 * @grid2: Right 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, sum[3][3], new[3][3], type;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			sum[i][j] = grid1[i][j] + grid2[i][j];
	type = stable(sum);
	if (type == 1)
	{
		copy_result(sum, grid1);
		return; }
	printf("=\n");
	print_grid(sum);
	while (type == 0)
	{
		new_grid(new);
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (sum[i][j] > 3)
				{	new[i][j] += sum[i][j] - 4;
					if (j + 1 == 1 || j + 1 == 2 || j + 1 == 0)
						new[i][j + 1] += 1;
					if (j - 1 == 1 || j - 1 == 2 || j - 1 == 0)
						new[i][j - 1] += 1;
					if (i + 1 == 1 || i + 1 == 2 || i + 1 == 0)
						new[i + 1][j] += 1;
					if (i - 1 == 1 || i - 1 == 2 || i - 1 == 0)
						new[i - 1][j] += 1; }
				else
					new[i][j] += sum[i][j]; } }
		type = stable(new);
		if (type == 1)
		{	copy_result(new, grid1);
			break; }
		printf("=\n");
		print_grid(new);
		copy_result(new, sum); /* change sum */
	}
}
