/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thessena <thessena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:28:24 by thessena          #+#    #+#             */
/*   Updated: 2024/11/01 11:35:56 by thessena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *text, ...);
int	check_type(char type, va_list args);
int	ft_printchar(char c);
int	ft_printnbr(int n);
int	ft_printstr(char *s);
int	ft_printperc(void);

#endif