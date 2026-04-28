/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mide-fre <mide-fre@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 19:34:22 by mide-fre          #+#    #+#             */
/*   Updated: 2026/04/28 16:37:10 by mide-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		ret;
	va_list	args;

	if (!format)
		return (0);
	ret = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			ret += ft_print(*(++format), args);
		else
			ret += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (ret);
}
