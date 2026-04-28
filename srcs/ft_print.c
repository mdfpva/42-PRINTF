/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mide-fre <mide-fre@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:41:04 by mide-fre          #+#    #+#             */
/*   Updated: 2026/04/28 15:37:44 by mide-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print(char c, va_list arg)
{
	int	ret;

	ret = 0;
	if (!c)
		return (0);
	else if (c == 'c')
		ret += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		ret += ft_putstr(va_arg(arg, char *));
	else if (c == 'p')
		ret += ft_putptr(va_arg(arg, void *));
	else if (c == 'd' || c == 'i')
		ret += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		ret += ft_putui(va_arg(arg, unsigned int));
	else if (c == 'x' || c == 'X')
		ret += ft_puthex(va_arg(arg, unsigned int), c);
	else if (c == '%')
		ret += ft_putchar('%');
	return (ret);
}
