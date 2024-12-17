/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatanagh <yatanagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 06:29:35 by yatanagh          #+#    #+#             */
/*   Updated: 2024/11/30 02:10:39 by yatanagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		while (str[i] != '\0')
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n *= -1;
		count += write(1, "-", 1);
	}
	if (n > 9)
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	if (n >= 0 && n <= 9)
	{
		n = n + '0';
		count += write(1, &n, 1);
	}
	return (count);
}

int	ft_printus(unsigned int n)
{
	int		count;
	char	nbr;

	count = 0;
	if (n > 9)
	{
		count += ft_printus(n / 10);
		count += ft_printus(n % 10);
	}
	if ((n > 0 && n < 10) || n == 0)
	{
		nbr = n + 48;
		count += write(1, &nbr, 1);
	}
	return (count);
}
