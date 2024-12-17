/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatanagh <yatanagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:57:58 by yatanagh          #+#    #+#             */
/*   Updated: 2024/12/17 01:26:43 by yatanagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_print(char f, va_list arg)
{
	if (f == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (f == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (f == 'd' || f == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (f == 'u')
		return (ft_printus(va_arg(arg, unsigned int)));
	else if (f == 'p')
		return (ft_printptr(va_arg(arg, void *)));
	else if (f == 'x' || f == 'X')
		return (ft_printhex(va_arg(arg, unsigned int), f));
	else if (f == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *f, ...)
{
	va_list	arg;
	int		count;

	count = 0;
	va_start(arg, f);
	if (!f)
	{
		return (-1);
	}
	while (*f != '\0')
	{
		if (*f == '%')
		{
			f++;
			if (*f == '\0')
				return (-1);
			else
				count = count + count_print(*f, arg);
		}
		else
			count = count + write(1, f, 1);
		f++;
	}
	va_end(arg);
	return (count);
}
