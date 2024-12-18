/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:09:27 by thessena          #+#    #+#             */
/*   Updated: 2024/11/05 17:51:26 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_recursive(int n)
{
	int	i;

	i = 0;
	if (n >= 10)
	{
		i += ft_putnbr_recursive(n / 10);
		if (i == -1)
			return (-1);
	}
	if (ft_putchar((n % 10) + '0') == -1)
		return (-1);
	return (i + 1);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		if (write(1, "-2", 2) == -1)
			return (-1);
		n = 147483648;
		i += 2;
	}
	else if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		n = -n;
		i++;
	}
	if (n == 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		return (i + 1);
	}
	i += ft_putnbr_recursive(n);
	return (i);
}
