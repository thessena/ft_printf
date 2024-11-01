/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:32:32 by thessena          #+#    #+#             */
/*   Updated: 2024/11/01 11:50:51 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *s)
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

int	ft_printnbr(int n)
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
		i += ft_printchar('-');
		n = -n;
	}
	if (n >= 10)
		i += ft_printnbr(n / 10);
	i += ft_printchar((n %= 10) + 48);
	return (i);
}

int	ft_printperc(void)
{
	write(1, "%", 1);
	return (1);
}

int	check_type(char type, va_list args)
{
	int	len;

	len = 0;
	if (type == 'c')
		len += ft_printchar(va_arg(args, int));
	else if (type == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (type == 'i')
		len += ft_printnbr(va_arg(args, int));
	else if (type == '%')
		len += ft_printperc();
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
			len += ft_printchar(*text);
		text++;
	}
	va_end(args);
	return (len);
}
