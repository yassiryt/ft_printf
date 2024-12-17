/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatanagh <yatanagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 02:08:57 by yatanagh          #+#    #+#             */
/*   Updated: 2024/12/14 23:07:59 by yatanagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned int n, const char f)
{
	char	nb;
	int		count;

	count = 0;
	if (n >= 16)
	{
		count += ft_printhex((n / 16), f);
		count += ft_printhex((n % 16), f);
	}
	else
	{
		if (n <= 9)
			nb = n + 48;
		else
		{
			if (f == 'x')
				nb = n - 10 + 97;
			else if (f == 'X')
				nb = n - 10 + 65;
		}
		count += write(1, &nb, 1);
	}
	return (count);
}

static int	ft_putptr(unsigned long n)
{
	int		count;
	char	nb;

	count = 0;
	if (n >= 16)
	{
		count += ft_putptr(n / 16);
		count += ft_putptr(n % 16);
	}
	else
	{
		if (n <= 9)
			nb = n + 48;
		else
			nb = n - 10 + 97;
		count += write(1, &nb, 1);
	}
	return (count);
}

int	ft_printptr(void *ptr)
{
	int				len;
	unsigned long	n;

	len = 2;
	n = (unsigned long)ptr;
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		write(1, "0x", 2);
		return (ft_putptr(n) + len);
	}
}
