#include "monty.h"

/**
 * openfile - opens a file
 * @thefile: the file namepath
 * Return: void
 */

void openfile(char *thefile)
{
FILE *fd = fopen(thefile, "r");
if (thefile == NULL || fd == NULL)
error(2, thefile);
readfile(fd);
fclose(fd);
}
/**
 * readfile - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void readfile(FILE *fd)
{
int line_number, format = 0;
char *buffr = NULL;
size_t len = 0;
for (line_number = 1; getline(&buffr, &len, fd) != -1; line_number++)
{
format = parseline(buffr, line_number, format);
}
free(buffr);
}
/**
 * parseline - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parseline(char *buffer, int line_number, int format)
{
char *op, *value;
const char *delim = "\n ";
if (buffer == NULL)
error(4);
op = strtok(buffer, delim);
if (op == NULL)
return (format);
value = strtok(NULL, delim);
if (strcmp(op, "stack") == 0)
return (0);
if (strcmp(op, "queue") == 0)
return (1);
findfunc(op, value, line_number, format);
return (format);
}
