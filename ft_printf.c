/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:32:32 by thessena          #+#    #+#             */
/*   Updated: 2024/11/05 12:59:51 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		write(1, "-2", 2);
		n = 147483648;
		i += 2;
	}
	if (n < 0)
	{
		i += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		i += ft_putnbr(n / 10);
	i += ft_putchar((n %= 10) + 48);
	return (i);
}

int	ft_putperc(void)
{
	write(1, "%", 1);
	return (1);
}

int	check_type(char type, va_list args)
{
	int	len;

	len = 0;
	if (type == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (type == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (type == 'i' || type == 'd')
		len += ft_putnbr(va_arg(args, int));
	else if (type == '%')
		len += ft_putperc();
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
