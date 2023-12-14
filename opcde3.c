#include "monty.h"

/**
 * mk_rotl - will rotate 1st element to the bottom and 2nd to the top
 * @dubly: indicates the linked list head
 * @mline: indicates line nummber
 */
void mk_rotl(stack_t **dubly, unsigned int mline)
{
	stack_t *axi1 = NULL;
	stack_t *axi2 = NULL;
	(void)mline;

	if (*dubly == NULL)
		return;

	if ((*dubly)->next == NULL)
		return;

	axi1 = (*dubly)->next;
	axi2 = *dubly;

	for (; axi2->next != NULL; axi2 = axi2->next)
		;

	axi1->prev = NULL;
	axi2->next = *dubly;
	(*dubly)->next = NULL;
	(*dubly)->prev = axi2;
	*dubly = axi1;
}

/**
 * mk_rotr - function reverses a stack
 * @dubly: indicates the linked list head
 * @mline: indicates the line number
 */
void mk_rotr(stack_t **dubly, unsigned int mline)
{
	stack_t *axi = NULL;
	(void)mline;

	if (*dubly == NULL)
		return;

	if ((*dubly)->next == NULL)
		return;

	axi = *dubly;

	for (; axi->next != NULL; axi = axi->next)
		;

	axi->prev->next = NULL;
	axi->next = *dubly;
	axi->prev = NULL;
	(*dubly)->prev = axi;
	*dubly = axi;
}
