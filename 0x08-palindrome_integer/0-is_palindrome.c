#include "palindrome.h"
/**
 * is_palindrome - checks whether or not a given unsigned integer
 * is a palindrome
 * @n: the number to be checked
 * Return: 1 if n is a palinfrom, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long q, rem, result = 0;


	q = n;
	while (q != 0)
	{
		rem = q % 10;
		result = result * 10 + rem;
		q = q / 10;
	}
	if (result == n)
		return (1);
	else
		return (0);
}
