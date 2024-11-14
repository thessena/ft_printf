/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:11:03 by thessena          #+#    #+#             */
/*   Updated: 2024/11/14 10:43:02 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	result;

	if (!s)
		return (write(1, "(null)", 6));
	i = 0;
	while (s[i])
	{
		result = write (1, &s[i], 1);
		if (result == -1)
			return (-1);
		i++;
	}
	return (i);
}
