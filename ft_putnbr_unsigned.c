/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:39:38 by thessena          #+#    #+#             */
/*   Updated: 2024/11/05 17:45:48 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (n >= 10)
	{
		count += ft_putnbr_unsigned(n / 10);
		if (count == -1)
			return (-1);
		i += count;
	}
	if (ft_putchar((n % 10) + '0') == -1)
		return (-1);
	return (i + 1);
}
