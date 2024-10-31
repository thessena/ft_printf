/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:32:32 by thessena          #+#    #+#             */
/*   Updated: 2024/10/31 11:27:35 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *text, ...)
{
	va_list	args;
	int		count;

	va_start(args, text);
	count = 0;
	while (*text)
	{
		if (*text == '%')
		{
			text++;
		}
		else
		{
			write(1, text, 1);
			count++;
		}
		text++;
	}
	va_end(args);
	return (count);
}
