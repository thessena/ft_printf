/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:47:19 by thessena          #+#    #+#             */
/*   Updated: 2024/11/14 14:38:55 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int	count;
	int	hex_count;

	count = 0;
	if (write(1, "0x", 2) == -1)
		return (-1);
	count += 2;
	hex_count = ft_puthex_lower((unsigned long)ptr);
	if (hex_count == -1)
		return (-1);
	count += hex_count;
	return (count);
}
