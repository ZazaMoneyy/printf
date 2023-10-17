#include "main.h"

/**
 * t_width - Estimates the width for printing
 * @format: Formatted string which is to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int t_width(const char *format, int *i, va_list list)
{
	int ww_i;
	int width = 0;

	for (ww_i = *i + 1; format[ww_i] != '\0'; ww_i++)
	{
		if (is_digit(format[ww_i]))
		{
			width *= 10;
			width += format[ww_i] - '0';
		}
		else if (format[ww_i] == '*')
		{
			ww_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = ww_i - 1;

	return (width);
}
