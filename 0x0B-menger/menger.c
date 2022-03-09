#include "menger.h"
/**
 * menger - function that draws a 2D Menger Sponge
 * @level:  is lower than 0, your function must do nothing
 *
 * Not returning just printing
 */
void menger(int level)
{
	int i_size = pow(3, level);

	int i_row = 0, i_rhigh = 0, i_colum = 0, i_chigh = 0;
	char c_print = '#';

	if (level < 0)
	{
		return;
	}

	for (; i_colum < i_size; i_colum++)
	{
		for (i_row = 0; i_row < i_size; i_row++)
		{
			c_print = '#';
			i_rhigh = i_row;
			i_chigh = i_colum;
			while (i_rhigh > 0 && i_chigh > 0 /* edge case */)
			{
				if (i_rhigh % 3 == 1 && i_chigh % 3 == 1)
				{
					c_print = ' ';
				}

				i_rhigh /= 3;
				i_chigh /= 3;
			}

			printf("%c", c_print);
		}

		printf("\n");
	}
}
