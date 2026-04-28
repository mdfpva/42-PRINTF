/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mide-fre <mide-fre@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:23:03 by mide-fre          #+#    #+#             */
/*   Updated: 2026/04/28 15:36:40 by mide-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "stdarg.h"
# include "unistd.h"
# include "stdint.h"

int	ft_printf(const char *format, ...);
int	ft_print(char c, va_list arg);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_puthex(unsigned int n, const char c);
int	ft_putptr(void *ptr);
int	ft_putnbr(int nbr);
int	ft_putui(unsigned int n);

#endif
