/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:23:37 by thessena          #+#    #+#             */
/*   Updated: 2024/11/01 10:04:20 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

int	ft_printf(const char *text, ...);

void	test_ft_printf(const char *text, ...)
{
	va_list	args1;
	va_list	args2;
	int		printf_result;
	int		ft_printf_result;

	printf("\nStandard printf:\n");
	va_start(args1, text);
	printf_result = vprintf(text, args1);
	va_end(args1);
	printf("Anzahl Zeichen (printf): %d\n", printf_result);
	printf("\nEigene ft_printf:\n");
	va_start(args2, text);
	ft_printf_result = ft_printf(text, args2);
	va_end(args2);
	printf("Anzahl Zeichen (ft_printf): %d\n\n", ft_printf_result);
	if (printf_result == ft_printf_result)
		printf("Erfolg: Funktionen geben gleiche Anzahl von Zeichen aus.\n");
	else
		printf("Fehler: Unterschiedliche Anzahl von Zeichen ausgegeben.\n\n");
}

int	main(void)
{
	test_ft_printf("Hallo Welt\n");
	// test_ft_printf("Zahl: %d\n", 42);
	// test_ft_printf("String: %s\n", "Test");
	// test_ft_printf("Char: %c\n", 'A');
	// test_ft_printf("Hexadezimal: %x\n", 255);
	// test_ft_printf("Große Zahl: %d\n", INT_MAX);
	// test_ft_printf("Negative Zahl: %d\n", -42);
	// test_ft_printf("Prozentzeichen: %%\n");
	return (0);
}
