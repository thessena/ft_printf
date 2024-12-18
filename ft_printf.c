/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:32:32 by thessena          #+#    #+#             */
/*   Updated: 2024/11/06 08:35:30 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(char type, va_list args)
{
	int	len;

	len = 0;
	if (type == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (type == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (type == 'p')
		len += ft_putptr(va_arg(args, void *));
	else if (type == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (type == 'd')
		len += ft_putnbr(va_arg(args, int));
	else if (type == 'u')
		len += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (type == 'x')
		len += ft_puthex_lower(va_arg(args, unsigned int));
	else if (type == 'X')
		len += ft_puthex_upper(va_arg(args, unsigned int));
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
			if (len == -1)
				return (-1);
		}
		else
		{
			len += ft_putchar(*text);
			if (len == -1)
				return (-1);
		}
		text++;
	}
	va_end(args);
	return (len);
}
