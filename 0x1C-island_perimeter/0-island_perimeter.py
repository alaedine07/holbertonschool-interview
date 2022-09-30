#!/usr/bin/python3
"""
    The perimeter of the island described in grid.
"""


def island_perimeter(grid):
    """
    Method:
    -------
        Calculate the perimeter of the island described in grid.
    Parameters:
    -----------
        grid: list of list of integers:
            -0 represents water
            -1 represents land
            -Each cell is square, with a side length of 1
            -Cells are connected horizontally/vertically (not diagonally).
            -grid is rectangular, with its width and height not exceeding 100.
    Returns:
    --------
        The perimeter of the island.
    """
    perimeter = 0
    nrows = len(grid)
    ncols = len(grid[0])
    for i in range(nrows):
        perimeter += sum(grid[i]) * 4
        for j in range(ncols):
            if grid[i][j] == 1:
                if j + 1 < ncols and grid[i][j + 1] == 1:
                    # remove one side from each grid cell
                    perimeter -= 2
                if i + 1 < nrows and grid[i + 1][j] == 1:
                    # remove one side from each grid cell
                    perimeter -= 2
    return perimeter
