#include "monty.h"
/**
 * error - Prints error messages determined by their error code.
 * @error_co: The error codes are the following:
 * (1) => The user does not give any file or more than one file to the program.
 * (2) => The file provided is not a file that can be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => When the program is unable to malloc more memory.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 */
void error(int error_co, ...)
{
va_list arg;
char *op;
int line_num;
va_start(arg, error_co);
switch (error_co)
{
case 1:
fprintf(stderr, "USAGE: monty file\n");
break;
case 2:
fprintf(stderr, "Error: Can't open file %s\n",
va_arg(arg, char *));
break;
case 3:
line_num = va_arg(arg, int);
op = va_arg(arg, char *);
fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op);
break;
case 4:
fprintf(stderr, "Error: malloc failed\n");
break;
case 5:
fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg, int));
break;
default:
break;
}
free_thenodes();
exit(EXIT_FAILURE);
}

