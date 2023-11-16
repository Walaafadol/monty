#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdarg.h>
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
extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);
void openfile(char *thefile);
int parseline(char *buffr, int linenumber, int format);
void readfile(FILE *);
int lenchars(FILE *);
void findfunc(char *, char *, int, int);
void callfun(op_func, char *, char *, int, int);
void error(int error_co, ...);
void more_error(int error_co, ...);
void string_error(int error_code, ...);
void rotr(stack_t **, unsigned int);
stack_t *create_thenode(int n);
void free_thenodes(void);
void print_thestack(stack_t **, unsigned int);
void addto_stack(stack_t **, unsigned int);
void addto_queue(stack_t **, unsigned int);
void print_tp(stack_t **, unsigned int);
void pop_tp(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swapnodes(stack_t **, unsigned int);

void addnodes(stack_t **, unsigned int);
void subnodes(stack_t **, unsigned int);
void divnodes(stack_t **, unsigned int);
void mulnodes(stack_t **, unsigned int);
void modnodes(stack_t **, unsigned int);


void print_char(stack_t **, unsigned int);
void print_str(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

#endif
