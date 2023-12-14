#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct globStrct - the global structure to use in functions
 * @mk_lifo: indicates the stack or queue
 * @curr: indicates the current line
 * @argmnt: the second parameter inside current line
 * @top: the linked list
 * @fl_desc: indicates the file descriptor
 * @bufr: indicates the input text
 *
 * Description: A doubly linked list node structure
 *              for stack, queues, LIFO, FIFO project
 */
typedef struct globStrct
{
	int mk_lifo;
	unsigned int curr;
	char  *argmnt;
	stack_t *top;
	FILE *fl_desc;
	char *bufr;
} glob_t;

/**
 * struct train_s - indicates variables(argmnts, files and line content)
 * @argmnt: the value
 * @mk_fle: points to the monty file
 * @cntnts: the line content
 * @mk_lifi: the flag change stack <-> queue
 * Description: will carry values through the program
 */
typedef struct train_s
{
	char *argmnt;
	FILE *mk_fle;
	char *cntnts;
	int mk_lifi;
}  train_t;
extern train_t train;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern glob_t mglob;

/* Used Function prototypes */
stack_t *addNde_end(stack_t **top, const int n);
stack_t *addNde(stack_t **top, const int n);
void freeLst(stack_t *top);

void free_mglob(void);

void mk_push(stack_t **stac, unsigned int line_numb);
void mk_pall(stack_t **stac, unsigned int line_numb);
void mk_pint(stack_t **dubly, unsigned int mline);
void mk_pop(stack_t **dubly, unsigned int mline);
void mk_swap(stack_t **dubly, unsigned int mline);
void mk_queue(stack_t **dubly, unsigned int mline);
void mk_stack(stack_t **dubly, unsigned int mline);
void mk_add(stack_t **dubly, unsigned int mline);
void mk_nop(stack_t **dubly, unsigned int mline);
void mk_sub(stack_t **top, unsigned int mline);
void mk_div(stack_t **dubly, unsigned int mline);
void mk_mul(stack_t **top, unsigned int mline);
void mk_mod(stack_t **dubly, unsigned int mline);
void mk_pchar(stack_t **dubly, unsigned int mline);
void mk_pstr(stack_t **dubly, unsigned int mline);
void mk_rotl(stack_t **dubly, unsigned int mline);
void mk_rotr(stack_t **dubly, unsigned int mline);

void (*fetch_opcdes(char *opcde))(stack_t **stac, unsigned int line_numb);

int mk_sch(char *d, char f);
char *mk_strtok(char *d, char *f);
void *mk_realloc(void *pter, unsigned int ol_sze, unsigned int nw_sze);
void *mk_calloc(unsigned int Nmembr, unsigned int sze);
int mk_strcmpre(char *st1, char *st2);

#endif /* __MONTY_H__ */
