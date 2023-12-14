#include "monty.h"

/**
 * mk_queue - will set the format of data to queue(FIFI/LILO)
 * @dubly: indicates the head of linked list
 * @mline: indicates line number
 */
void mk_queue(stack_t **dubly, unsigned int mline)
{
	(void)dubly;
	(void)mline;

	mglob.mk_lifo = 0;
}

/**
 * mk_stack - will set the format of data to stack (LIFO/FILO)
 * @dubly: indicates the linked list head
 * @mline: indicates the line number
 */
void mk_stack(stack_t **dubly, unsigned int mline)
{
	(void)dubly;
	(void)mline;

	mglob.mk_lifo = 1;
}
