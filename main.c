#include "monty.h"

void (*f)(stack_t **stack, unsigned int line_number);
glob_t mglob;
/**
 * free_mglob - function frees the global variables
 *
 * Return: no return
 */
void free_mglob(void)
{
	freeLst(mglob.top);
	free(mglob.bufr);
	fclose(mglob.fl_desc);
}

/**
 * begin_mglob - will initialize global variables
 *
 * @fld: indicates the file descriptor
 * Return: void
 */
void begin_mglob(FILE *fld)
{
	mglob.mk_lifo = 1;
	mglob.curr = 1;
	mglob.argmnt = NULL;
	mglob.top = NULL;
	mglob.fl_desc = fld;
	mglob.bufr = NULL;
}

/**
 * assess_input - checks if the file exists and if it can be opened
 *
 * @argcnt: argument count
 * @argvec: argument vector
 * Return: file struct will be returned
 */
FILE *assess_input(int argcnt, char *argvec[])
{
	FILE *fld;

	if (argcnt == 1 || argcnt > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fld = fopen(argvec[1], "r");

	if (fld == NULL)
	{
		dprintf(2, "Error: Cannot open file %s\n", argvec[1]);
		exit(EXIT_FAILURE);
	}

	return (fld);
}

/**
 * main - Entry point
 *
 * @argcnt: argument count
 * @argvec: argument vector
 * Return: 0 if successful
 */
int main(int argcnt, char *argvec[])
{
	FILE *fld;
	size_t sze = 256;
	ssize_t mlnes = 0;
	char *lne[2] = {NULL, NULL};

	fld = assess_input(argcnt, argvec);
	begin_mglob(fld);
	mlnes = getline(&mglob.bufr, &sze, fld);
	while (mlnes != -1)
	{
		lne[0] = mk_strtok(mglob.bufr, " \t\n");
		if (lne[0] && lne[0][0] != '#')
		{
			f = fetch_opcdes(lne[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", mglob.curr);
				dprintf(2, "unknown instruction %s\n", lne[0]);
				free_mglob();
				exit(EXIT_FAILURE);
			}
			mglob.argmnt = mk_strtok(NULL, " \t\n");
			f(&mglob.top, mglob.curr);
		}
		mlnes = getline(&mglob.bufr, &sze, fld);
		mglob.curr++;
	}

	free_mglob();

	return (0);
}
