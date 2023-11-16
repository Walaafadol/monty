#include "monty.h"
/**
* addto_stack - Adds a node to the stack.
* @new_node: Pointer to the new node.
* @ln: Interger representing the line number of of the opcode.
*/
void addto_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
stack_t *tp;
if (new_node == NULL || *new_node == NULL)
exit(EXIT_FAILURE);
if (head == NULL)
{
head = *new_node;
return;
}
tp = head;
head = *new_node;
head->next = tp;
tp->prev = head;
}
/**
 * print_thestack - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 */
void print_thestack(stack_t **stack, unsigned int line_number)
{
stack_t *tp;
(void) line_number;
if (stack == NULL)
exit(EXIT_FAILURE);
tp = *stack;
while (tp != NULL)
{
printf("%d\n", tp->n);
tp = tp->next;
}
}
