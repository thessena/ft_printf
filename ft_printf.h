/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:28:24 by thessena          #+#    #+#             */
/*   Updated: 2024/11/14 15:36:44 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *text, ...);
int	check_type(char type, va_list args);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putptr(void *ptr);
int	ft_putnbr(int n);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_puthex_lower(unsigned long n);
int	ft_puthex_upper(unsigned long n);
int	ft_putperc(void);

#endif
