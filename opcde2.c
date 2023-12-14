#include "monty.h"

/**
 * mk_mod - calculates rest of the division of the second element
 *          by the top element of the stack
 * @dubly: indicates the head of the linked list
 * @mline: indicates the line number
 * Return: void
 * description: result is stored in 2nd value node
 * from top and top value removed.
 */

void mk_mod(stack_t **dubly, unsigned int mline)
{
	int d = 0;
	stack_t *axi = NULL;

	axi = *dubly;

	for (; axi != NULL; axi = axi->next, d++)
		;

	if (d < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", mline);
		free_mglob();
		exit(EXIT_FAILURE);
	}

	if ((*dubly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", mline);
		free_mglob();
		exit(EXIT_FAILURE);
	}

	axi = (*dubly)->next;
	axi->n %= (*dubly)->n;
	mk_pop(dubly, mline);
}
/**
 * mk_pstr - function will print string of the stack
 *
 * @dubly: indicates head of the linked list
 * @mline: line number
 * Return: void
 */
void mk_pstr(stack_t **dubly, unsigned int mline)
{
	stack_t *axi;
	(void)mline;

	axi = *dubly;

	while (axi && axi->n > 0 && axi->n < 128)
	{
		printf("%c", axi->n);
		axi = axi->next;
	}

	printf("\n");
}
/**
 * mk_pchar - function will print char value of the first element
 *
 * @dubly: indicates the head of linked list
 * @mline: indicates the line number
 * Return: void
 */
void mk_pchar(stack_t **dubly, unsigned int mline)
{
	if (dubly == NULL || *dubly == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", mline);
		free_mglob();
		exit(EXIT_FAILURE);
	}
	if ((*dubly)->n < 0 || (*dubly)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", mline);
		free_mglob();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*dubly)->n);
}
