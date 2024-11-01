/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:23:37 by thessena          #+#    #+#             */
/*   Updated: 2024/11/01 11:51:15 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

int	ft_printf(const char *text, ...);

int	main(void)
{
	int	len;

	len = 0;
	ft_printf("Hallo Welt\n");
	ft_printf("Char: %c\n", 'A');
	ft_printf("String: %s\n", "Test");
	len += ft_printf("Zahl: %i\n", 42);
	printf("%i\n", len);
	return (0);
}

	// ft_printf("Hexadezimal: %x\n", 255);
	// ft_printf("Große Zahl: %d\n", INT_MAX);
	// ft_printf("Negative Zahl: %d\n", -42);
	// ft_printf("Prozentzeichen: %%\n");