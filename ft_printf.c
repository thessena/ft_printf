/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:32:32 by thessena          #+#    #+#             */
/*   Updated: 2024/11/01 10:57:00 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2", 2);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n %= 10) + 48);
	return (1);
}

int	check_type(char type, va_list args)
{
	int	len;

	len = 0;
	if (type == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (type == 'i')
		len += ft_putnbr(va_arg(args, int));
	return (len);
}

int	ft_printf(const char *text, ...)
{
	va_list	args;
	int		len;

	va_start(args, text);
	len = 0;
	while (*text)
	{
		if (*text == '%')
		{
			text++;
			len += check_type(*text, args);
		}
		else
			len += ft_putchar(*text);
		text++;
	}
	va_end(args);
	return (len);
}
