#include "monty.h"

/**
 * mk_push - pushes an element to the stack
 *
 * @dubly: indicates the head of linked list
 * @mline: indicates the line number
 * Return: void
 */
void mk_push(stack_t **dubly, unsigned int mline)
{
	int x, y;

	if (!mglob.argmnt)
	{
		dprintf(2, "L%u: ", mline);
		dprintf(2, "usage: push integer\n");
		free_mglob();
		exit(EXIT_FAILURE);
	}

	for (y = 0; mglob.argmnt[y] != '\0'; y++)
	{
		if (!isdigit(mglob.argmnt[y]) && mglob.argmnt[y] != '-')
		{
			dprintf(2, "L%u: ", mline);
			dprintf(2, "usage: push integer\n");
			free_mglob();
			exit(EXIT_FAILURE);
		}
	}

	x = atoi(mglob.argmnt);

	if (mglob.mk_lifo == 1)
		addNde(dubly, x);
	else
		addNde_end(dubly, x);
}

/**
 * mk_pall - will print all values on the stack
 *
 * @dubly: indicates head of linked list
 * @mline: indicates the line numbers
 * Return: void
 */
void mk_pall(stack_t **dubly, unsigned int mline)
{
	stack_t *axi;
	(void)mline;

	axi = *dubly;

	while (axi)
	{
		printf("%d\n", axi->n);
		axi = axi->next;
	}
}


/**
 * mk_pint - will print the value at the top of the stack
 *
 * @dubly: indicates the head of the linked list
 * @mline: indicates the line number
 * Return: void
 */
void mk_pint(stack_t **dubly, unsigned int mline)
{
	(void)mline;

	if (*dubly == NULL)
	{
		dprintf(2, "L%u: ", mline);
		dprintf(2, "can't pint, stack empty\n");
		free_mglob();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*dubly)->n);
}

/**
 * mk_pop - will remove the top element of the stack
 *
 * @dubly: indicates the head of the linked list
 * @mline: line number
 * Return: void
 */
void mk_pop(stack_t **dubly, unsigned int mline)
{
	stack_t *axi;

	if (dubly == NULL || *dubly == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", mline);
		free_mglob();
		exit(EXIT_FAILURE);
	}
	axi = *dubly;
	*dubly = (*dubly)->next;
	free(axi);
}


/**
 * mk_swap - will swap the top two elements of the stack
 *
 * @dubly: indicates the head of the linked list
 * @mline: indicates the line number
 * Return: void
 */
void mk_swap(stack_t **dubly, unsigned int mline)
{
	int x = 0;
	stack_t *axi = NULL;

	axi = *dubly;

	for (; axi != NULL; axi = axi->next, x++)
		;

	if (x < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", mline);
		free_mglob();
		exit(EXIT_FAILURE);
	}

	axi = *dubly;
	*dubly = (*dubly)->next;
	axi->next = (*dubly)->next;
	axi->prev = *dubly;
	(*dubly)->next = axi;
	(*dubly)->prev = NULL;
}
