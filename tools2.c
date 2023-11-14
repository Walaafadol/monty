# include "monty.h"
/**
 * find_func - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void findfunc(char *opcode, char *value, int ln, int format)
{
int i;
int flag;

instruction_t func_list[] = {
{"push", add_to_stack},
{"pall", print_stack},
{"pint", print_top},
{"pop", pop_top},
{"nop", nop},
{"swap", swap_nodes},
{"add", add_nodes},
{"sub", sub_nodes},
{"div", div_nodes},
{"mul", mul_nodes},
{"mod", mod_nodes},
{"pchar", print_char},
{"pstr", print_str},
{"rotl", rotl},
{"rotr", rotr},
{NULL, NULL}
};

if (opcode[0] == '#')
return;
for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
{
if (strcmp(opcode, func_list[i].opcode) == 0)
{
callfun(funclist[i].f, opcode, value, ln, format);
flag = 0;
}
if (flag == 1)
error(3, ln, opcode);
}
/**
 * call_fun - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void callfun(op_func func, char *opc, char *valu, int ln, int format)
{
stack_t *node;
int flag;
int i;
flag = 1;
if (strcmp(opc, "push") == 0)
{
if (valu != NULL && valu[0] == '-')
{
valu = valu + 1;
flag = -1;
}
if (valu == NULL)
error(5, ln);
for (i = 0; valu[i] != '\0'; i++)
{
if (isdigit(valu[i]) == 0)
error(5, ln);
}
node = create_node(atoi(valu) * flag);
if (format == 0)
func(&node, ln);
if (format == 1)
add_to_queue(&node, ln);
}
else
func(&head, ln);

