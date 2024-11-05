/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:28:24 by thessena          #+#    #+#             */
/*   Updated: 2024/11/05 12:32:12 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *text, ...);
int	check_type(char type, va_list args);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putint(int n);
int	ft_putdec(int n);
int	ft_putperc(void);

#endif