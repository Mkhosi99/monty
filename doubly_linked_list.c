#include "monty.h"

/**
 *addNde_end - will add node at end of doubly linked list
 *@top: indicates the first position of linked list
 *@n: the data to store in linked list
 *Return: doubly linked list will be returned
 */
stack_t *addNde_end(stack_t **top, const int n)
{
	stack_t *tmp, *axi;

	if (top == NULL)
		return (NULL);
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_mglob();
		exit(EXIT_FAILURE);
	}
	tmp->n = n;

	if (*top == NULL)
	{
		tmp->next = *top;
		tmp->prev = NULL;
		*top = tmp;
		return (*top);
	}
	axi = *top;
	while (axi->next)
		axi = axi->next;
	tmp->next = axi->next;
	tmp->prev = axi;
	axi->next = tmp;
	return (axi->next);
}

/**
 *addNde - adds note at the start of doubly link list
 *@top: starting point of linked list
 *@n: the data to store in list
 *Return: doubly linked list will return
 */
stack_t *addNde(stack_t **top, const int n)
{
	stack_t *tmp;

	if (top == NULL)
		return (NULL);
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_mglob();
		exit(EXIT_FAILURE);
	}
	tmp->n = n;

	if (*top == NULL)
	{
		tmp->next = *top;
		tmp->prev = NULL;
		*top = tmp;
		return (*top);
	}
	(*top)->prev = tmp;
	tmp->next = (*top);
	tmp->prev = NULL;
	*top = tmp;
	return (*top);
}

/**
 * freeLst - function frees the doubly linked list
 *
 * @top: indicates head of the list
 * Return: void
 */
void freeLst(stack_t *top)
{
	stack_t *tp;

	while ((tp = top) != NULL)
	{
		top = top->next;
		free(tp);
	}
}
