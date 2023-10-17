#include "main.h"

/**
 * t_flags - flags
 * @format: arguments
 * @i: parameter.
 * Return: print
 */
int t_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, ww_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (ww_i = *i + 1; format[ww_i] != '\0'; ww_i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[ww_i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = ww_i - 1;

	return (flags);
}
