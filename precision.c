#include "main.h"

/**
 * t_precision - Estimates the precision
 * @format: arguments
 * @i: arguments to be printed.
 * @list: list
 *
 * Return: Precision.
 */
int t_precision(const char *format, int *i, va_list list)
{
	int ww_i = *i + 1;
	int precision = -1;

	if (format[ww_i] != '.')
		return (precision);

	precision = 0;

	for (ww_i += 1; format[ww_i] != '\0'; ww_i++)
	{
		if (is_digit(format[ww_i]))
		{
			precision *= 10;
			precision += format[ww_i] - '0';
		}
		else if (format[ww_i] == '*')
		{
			ww_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = ww_i - 1;

	return (precision);
}

