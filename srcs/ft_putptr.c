/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mide-fre <mide-fre@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 12:57:09 by mide-fre          #+#    #+#             */
/*   Updated: 2026/04/28 19:25:06 by mide-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_puthex_ptr(uintptr_t n)
{
	int		ret;
	char	*base;

	ret = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		ret += ft_puthex_ptr(n / 16);
	ret += write(1, &base[n % 16], 1);
	return (ret);
}

int	ft_putptr(void *ptr)
{
	int	ret;

	if (!ptr)
		return (ft_putstr("(nil)"));
	ret = 0;
	ret += ft_putstr("0x");
	ret += ft_puthex_ptr((uintptr_t)ptr);
	return (ret);
}
