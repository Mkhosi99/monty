#include "monty.h"

/**
 * fetch_opcdes - will select correct opcode to perform
 *
 * @opcde: opcode passed
 *
 * Return: pointer to the function that executes the opcode
 */
void (*fetch_opcdes(char *opcde))(stack_t **stac, unsigned int line_numb)
{
	instruction_t instruction[] = {
		{"push", mk_push},
		{"pall", mk_pall},
		{"pint", mk_pint},
		{"pop", mk_pop},
		{"swap", mk_swap},
		{"add", mk_add},
		{"nop", mk_nop},
		{"sub", mk_sub},
		{"div", mk_div},
		{"mul", mk_mul},
		{"mod", mk_mod},
		{"pchar", mk_pchar},
		{"pstr", mk_pstr},
		{"rotl", mk_rotl},
		{"rotr", mk_rotr},
		{"stack", mk_stack},
		{"queue", mk_queue},
		{NULL, NULL}
	};
	int x;

	for (x = 0; instruction[x].opcode; x++)
	{
		if (mk_strcmpre(instruction[x].opcode, opcde) == 0)
			break;
	}

	return (instruction[x].f);
}
