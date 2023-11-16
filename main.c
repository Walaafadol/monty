#include "monty.h"
/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
openfile(argv[1]);
free_thenodes();
return (0);
}

/**
 * create_thenode - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *create_thenode(int n)
{
stack_t *node;

node = malloc(sizeof(stack_t));
if (node == NULL)
error(4);
node->next = NULL;
node->prev = NULL;
node->n = n;
return (node);
}

/**
 * free_thenodes - Frees nodes in the stack.
 */
void free_thenodes(void)
{
stack_t *tmp;
if (head == NULL)
return;
while (head != NULL)
{
tmp = head;
head = head->next;
free(tmp);
}
}
/**
 * addto_queue - Adds a node to the queue.
 * @newnode: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void addto_queue(stack_t **newnode, __attribute__((unused))unsigned int ln)
{
stack_t *tmp;
if (newnode == NULL || *newnode == NULL)
exit(EXIT_FAILURE);
if (head == NULL)
{
head = *newnode;
return;
}
tmp = head;
while (tmp->next != NULL)
tmp = tmp->next;
tmp->next = *newnode;
(*newnode)->prev = tmp;
}
