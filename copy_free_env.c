#include "shell.h"

char **_copyenv(void);
void free_env(void);
char **_getenv(const char *var);

/**
 * _copyenv - Duplicates the current environment variables.
 *
 * Return: If an error occurs, NULL is returned.
 *         Otherwise, a double pointer to the duplicated environment is returned.
 */

char **_copyenv(void)
{
	char **new_environ;
	size_t size;
	int index;

	for (size = 0; environ[size]; size++)
		;

	new_environ = malloc(sizeof(char *) * (size + 1));
	if (!new_environ)
		return (NULL);

	for (index = 0; environ[index]; index++)
	{
		new_environ[index] = malloc(_strlen(environ[index]) + 1);

		if (!new_environ[index])
		{
			for (index--; index >= 0; index--)
				free(new_environ[index]);
			free(new_environ);
			return (NULL);
		}
		_strcpy(new_environ[index], environ[index]);
	}
	new_environ[index] = NULL;

	return (new_environ);
}

/**
 * free_env - Releases the memory used by the duplicated environment.
 */

void free_env(void)
{
	int index;

	for (index = 0; environ[index]; index++)
		free(environ[index]);
	free(environ);
}

/**
 * _getenv - Retrieves the value of an environmental variable from the PATH.
 * @var: The name of the environmental variable to retrieve.
 *
 * Return: If the environmental variable does not exist, returns NULL.
 *         Otherwise, returns a pointer to the environmental variable's value.
 */

char **_getenv(const char *var)
{
	int index, len;

	len = _strlen(var);
	for (index = 0; environ[index]; index++)
	{
		if (_strncmp(var, environ[index], len) == 0)
			return (&environ[index]);
	}

	return (NULL);
}
