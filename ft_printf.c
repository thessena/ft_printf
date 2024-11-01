/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:32:32 by thessena          #+#    #+#             */
/*   Updated: 2024/11/01 10:06:33 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	check_type(char type, va_list args)
{
	int	len;

	len = 0;
	if (type == 'c')
	{
		len += ft_putchar(va_arg(args, int));
	}
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
