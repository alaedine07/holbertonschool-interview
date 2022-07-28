#include <stdbool.h>
#include <stdio.h>

/**
 * wildcmp - function that compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 1 if the strings can be considered identical, else 0
 */
int wildcmp(char *s1, char *s2)
{
	if (!*s1)
	{
		if (*s2 == '*')
			return (wildcmp(s1, s2 + 1));
		return (!*s2);
	}
	if (*s2 == '*')
		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	return (0);
}
