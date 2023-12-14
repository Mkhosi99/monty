#include "monty.h"
/**
 * mk_strcmpre - Function will compare two strings.
 * @st1: string 1
 * @st2: string 1
 * Return: 0 if st1 & st2 equal
 *         another value if otherwise
 */
int mk_strcmpre(char *st1, char *st2)
{
	int x;

	for (x = 0; st1[x] == st2[x] && st1[x]; x++)
		;
	if (st1[x] > st2[x])
		return (1);
	if (st1[x] < st2[x])
		return (-1);
	return (0);
}

/**
 * mk_sch - function will search if a char is inside a string
 * @d: string to assess
 * @f: the char to find
 * Return: 1 if success and 0 if otherwise
 */
int mk_sch(char *d, char f)
{
	int srch = 0;

	while (d[srch] != '\0')
	{
		if (d[srch] == f)
		{
			break;
		}
		srch++;
	}
	if (d[srch] == f)
		return (1);
	else
		return (0);
}

/**
 * mk_strtok - function tokenizes string depending on the delimit
 * @d: string to tokenize
 * @f: indicates the delimiters
 * Return: first partition
 */
char *mk_strtok(char *d, char *f)
{
	static char *ult;
	int x = 0, y = 0;

	if (!d)
		d = ult;
	while (d[x] != '\0')
	{
		if (mk_sch(f, d[x]) == 0 && d[x + 1] == '\0')
		{
			ult = d + x + 1;
			*ult = '\0';
			d = d + y;
			return (d);
		}
		else if (mk_sch(f, d[x]) == 0 && mk_sch(f, d[x + 1]) == 0)
			x++;
		else if (mk_sch(f, d[x]) == 0 && mk_sch(f, d[x + 1]) == 1)
		{
			ult = d + x + 1;
			*ult = '\0';
			ult++;
			d = d + y;
			return (d);
		}
		else if (mk_sch(f, d[x]) == 1)
		{
			y++;
			x++;
		}
	}
	return (NULL);
}
