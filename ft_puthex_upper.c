/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:44:37 by thessena          #+#    #+#             */
/*   Updated: 2024/11/05 17:04:37 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_upper(unsigned long n)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789ABCDEF";
	if (n >= 16)
	{
		count += ft_puthex_upper(n / 16);
		if (count == -1)
			return (-1);
	}
	count += ft_putchar(base[n % 16]);
	if (count == -1)
		return (-1);
	return (count);
}
