#include "shell.h"

int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);
/**
 * _strlen - Computes the length of a string.
 * @s: A pointer to the character string.
 *
 * Return: The length of the character string.
 */

int _strlen(const char *s)
{
	int length = 0;

	if (!s)
		return (length);
	for (length = 0; s[length]; length++)
		;
	return (length);
}
/**
 * custom_strcpy - Copies the string from src to dest, including the
 *                 null-terminating byte.
 * @dest: Pointer to the destination buffer.
 * @src: Pointer to the source string.
 *
 * This function copies the content of the source string to the destination
 * buffer, including the null-terminating byte. It ensures that the destination
 * buffer is large enough to accommodate the source string.
 *
 * Returns: Pointer to the destination buffer (dest).
 */
char *_strcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * custom_strcat - Concatenates two strings.
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 *
 * This function appends the content of the source string to the end of the
 * destination string. It assumes that the destination string has enough space
 * to accommodate the concatenated result.
 *
 * Returns: Pointer to the destination string (dest).
 */
char *_strcat(char *dest, const char *src)
{
	char *destTemp;
	const char *srcTemp;

	destTemp = dest;
	srcTemp =  src;

	while (*destTemp != '\0')
		destTemp++;

	while (*srcTemp != '\0')
		*destTemp++ = *srcTemp++;
	*destTemp = '\0';
	return (dest);
}

/**
 * custom_strncat - Concatenates two strings, copying up to n bytes from source.
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 * @n: Number of bytes to copy from src.
 *
 * This function appends the content of the source string to the end of the
 * destination string, copying at most n bytes from the source. It assumes that
 * the destination string has enough space to accommodate the concatenated result
 * along with the null-terminating byte.
 *
 * Returns: Pointer to the destination string (dest).
 */

char *_strncat(char *dest, const char *src, size_t n)
{
	size_t dest_len = _strlen(dest);
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

	return (dest);
}
