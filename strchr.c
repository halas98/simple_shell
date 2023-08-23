#include "shell.h"

char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);

/**
 * _strchr - Locate a character within a string.
 * @s: The string to search in.
 * @c: The character to locate.
 *
 * Return: If c is found, a pointer to the first occurrence.
 *         If c is not found, returns NULL.
 */
char *_strchr(char *s, char c)
{
	int index;

	for (index = 0; s[index]; index++)
	{
		if (s[index] == c)
			return (s + index);
	}

	return (NULL);
}

/**
 * _strspn - Calculate the length of a prefix substring.
 * @s: The string to search within.
 * @accept: The prefix to measure.
 *
 * Return: The count of bytes in s that exclusively
 *         consist of bytes from accept.
 */
int _strspn(char *s, char *accept)
{
	int bytes = 0;
	int index;

	while (*s)
	{
		for (index = 0; accept[index]; index++)
		{
			if (*s == accept[index])
			{
				bytes++;
				break;
			}
		}
		s++;
	}
	return (bytes);
}

/**
 * _strcmp - Compare two strings.
 * @s1: The first string for comparison.
 * @s2: The second string for comparison.
 *
 * Return: Positive byte difference if s1 > s2,
 *         0 if s1 = s2,
 *         Negative byte difference if s1 < s2.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);

	return (0);
}

/**
 * _strncmp - Compare two strings.
 * @s1: Pointer to the first string.
 * @s2: Pointer to the second string.
 * @n: The number of bytes to compare.
 *
 * Return: Negative value if s1 is shorter than s2.
 *         0 if s1 and s2 match.
 *         Positive value if s1 is longer than s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
	}
	if (i == n)
		return (0);
	else
		return (-15);
}
