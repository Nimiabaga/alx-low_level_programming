#include "main.h"

/**
 * _puts_recursion - recursive function to priny to screen
 *
 * @s: pointer to the string 
 *
 * Return: 0
 */
void _puts_recursion(char *s)
{
	if (*s != '\0')
	{

		_putchar(*s);
		_puts_recursion(s + 1);
	}
	if (*s == '\0')
	{
		_putchar('\n');
	
	}
}
