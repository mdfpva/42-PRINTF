/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mide-fre <mide-fre@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 12:42:37 by mide-fre          #+#    #+#             */
/*   Updated: 2026/04/28 15:40:55 by mide-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_puthex(unsigned int n, const char c)
{
	int		ret;
	char	*base;

	ret = 0;
	base = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	if (n >= 16)
		ret += ft_puthex((n / 16), c);
	ret += ft_putchar(base[n % 16]);
	return (ret);
}
