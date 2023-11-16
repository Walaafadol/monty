# include "monty.h"
/**
 * more_error - handles errors.
 * @error_co: The error codes are the following:
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 * (9) => Division by zero.
 */
void more_error(int error_co, ...)
{
va_list arg;
char *op;
int line_num;
va_start(arg, error_co);
switch (error_co)
{
case 6:
fprintf(stderr, "L%d: can't pint, stack empty\n",
va_arg(arg, int));
break;
case 7:
fprintf(stderr, "L%d: can't pop an empty stack\n",
va_arg(arg, int));
break;
case 8:
line_num = va_arg(arg, unsigned int);
op = va_arg(arg, char *);
fprintf(stderr, "L%d: can't %s, stack too short\n", line_num, op);
break;
case 9:
fprintf(stderr, "L%d: division by zero \n",
va_arg(arg, unsigned int));
break;
default:
break;
}
free_thenodes();
exit(EXIT_FAILURE);
}
/**
 * string_error - handles errors.
 * @error_code: The error codes are the following:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void string_error(int error_code, ...)
{
va_list arg;
int line_num;
va_start(arg, error_code);
line_num = va_arg(arg, int);
switch (error_code)
{
case 10:
fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
break;
case 11:
fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
break;
default:
break;
}
free_thenodes();
exit(EXIT_FAILURE);
}
