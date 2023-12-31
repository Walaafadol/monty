#include "monty.h"
/**
 * pop_tp - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void pop_tp(stack_t **stack, unsigned int line_number)
{
stack_t *tmp;

if (stack == NULL || *stack == NULL)
more_error(7, line_number);
tmp = *stack;
*stack = tmp->next;
if (*stack != NULL)
(*stack)->prev = NULL;
free(tmp);
}

/**
 * print_tp - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void print_tp(stack_t **stack, unsigned int line_number)
{
if (stack == NULL || *stack == NULL)
more_error(6, line_number);
printf("%d\n", (*stack)->n);
}
