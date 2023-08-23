#include "shell.h"

int token_len(char *str, char *delim);
int count_tokens(char *str, char *delim);
char **_strtok(char *line, char *delim);

/**
 * find_token_end - Finds the index of the delimiter marking the end
 *                  of the first token within a string.
 * @str: The string to be searched.
 * @delim: The delimiter character.
 *
 * This function searches for the first occurrence of the delimiter character
 * within the provided string. It returns the index where the delimiter is found,
 * marking the end of the initial token pointed to by str.
 *
 * Returns: The index of the delimiter marking the end of the initial token,
 *          or -1 if the delimiter is not found.
 */

int token_len(char *str, char *delim)
{
	int index = 0, len = 0;

	while (*(str + index) && *(str + index) != *delim)
	{
		len++;
		index++;
	}

	return (len);
}

/**
 * count_delimited_words - Counts the number of delimited words within a string.
 * @str: The string to be searched.
 * @delim: The delimiter character.
 *
 * This function counts the number of words within the provided string that are
 * separated by the specified delimiter character. A word is considered a sequence
 * of characters that is not the delimiter.
 *
 * Returns: The number of delimited words contained within the string.
 */

int count_tokens(char *str, char *delim)
{
	int index, tokens = 0, len = 0;

	for (index = 0; *(str + index); index++)
		len++;

	for (index = 0; index < len; index++)
	{
		if (*(str + index) != *delim)
		{
			tokens++;
			index += token_len(str + index, delim);
		}
	}

	return (tokens);
}
/**
 * custom_strtok - Splits a string into tokens.
 * @line: The string to be tokenized.
 * @delim: The delimiter character for tokenization.
 *
 * This function splits the given string into tokens using the specified delimiter.
 * It returns a pointer to an array containing the tokenized words.
 *
 * Returns: A pointer to an array of tokenized words.
 */

char **_strtok(char *line, char *delim)
{
	char **ptr;
	int index = 0, tokens, t, letters, l;

	tokens = count_tokens(line, delim);
	if (tokens == 0)
		return (NULL);

	ptr = malloc(sizeof(char *) * (tokens + 2));
	if (!ptr)
		return (NULL);

	for (t = 0; t < tokens; t++)
	{
		while (line[index] == *delim)
			index++;

		letters = token_len(line + index, delim);

		ptr[t] = malloc(sizeof(char) * (letters + 1));
		if (!ptr[t])
		{
			for (index -= 1; index >= 0; index--)
				free(ptr[index]);
			free(ptr);
			return (NULL);
		}

		for (l = 0; l < letters; l++)
		{
			ptr[t][l] = line[index];
			index++;
		}

		ptr[t][l] = '\0';
	}
	ptr[t] = NULL;
	ptr[t + 1] = NULL;

	return (ptr);
}
