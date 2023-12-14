#include "monty.h"

/**
 * mk_add - will add the top two values of stack_t linked list
 * @dubly: indicates the head of linked list
 * @mline: indicates the line number
 * Description: result is stored in second node value
 * from the top and top value is removed
 */
void mk_add(stack_t **dubly, unsigned int mline)
{
	int d = 0;
	stack_t *axi = NULL;

	axi = *dubly;

	for (; axi != NULL; axi = axi->next, d++)
		;

	if (d < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", mline);
		free_mglob();
		exit(EXIT_FAILURE);
	}

	axi = (*dubly)->next;
	axi->n += (*dubly)->n;
	mk_pop(dubly, mline);
}

/**
 * mk_nop - function will not do anything
 * @dubly: indicates the linked list head
 * @mline: indicates the line number
 */
void mk_nop(stack_t **dubly, unsigned int mline)
{
	(void)dubly;
	(void)mline;
}
/**
 * mk_sub - Subtracts 2nd value from top of stack_t linked list by top value.
 * @top: indicates the head node
 * @mline: indicates the line number
 * Description: result is stored in 2nd value node
 * from the top and the top value is removed.
 */

void mk_sub(stack_t **top, unsigned int mline)
{
	int d = 0;
	stack_t *currnt;

	currnt = *top;

	for (; currnt != NULL; currnt = currnt->next, d++)
		;

	if (d < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", mline);
		free_mglob();
		exit(EXIT_FAILURE);
	}

	currnt = (*top)->next;
	currnt->n -= (*top)->n;
	mk_pop(top, mline);
}

/**
 * mk_div - Divides 2nd value from the top of linkedlist by the top value
 * @dubly: indicates head of the linked list
 * @mline: indicates the line number
 * Return: void
 */

void mk_div(stack_t **dubly, unsigned int mline)
{
	int d = 0;
	stack_t *axi = NULL;

	axi = *dubly;

	for (; axi != NULL; axi = axi->next, d++)
		;

	if (d < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", mline);
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
	axi->n /= (*dubly)->n;
	mk_pop(dubly, mline);
}

/**
 * mk_mul - Multiplies 2nd value from top of linked list by top value
 * @top: the head node
 * @mline: the line number
 * description: result is stored in 2nd value node
 * from the top and top value removed
 */

void mk_mul(stack_t **top, unsigned int mline)
{
	int d = 0;
	stack_t *currnt;

	currnt = *top;

	for (; currnt != NULL; currnt = currnt->next, d++)
		;

	if (d < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", mline);
		free_mglob();
		exit(EXIT_FAILURE);
	}

	currnt = (*top)->next;
	currnt->n *= (*top)->n;
	mk_pop(top, mline);
}
