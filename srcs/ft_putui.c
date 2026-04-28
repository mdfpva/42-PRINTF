/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mide-fre <mide-fre@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 13:16:50 by mide-fre          #+#    #+#             */
/*   Updated: 2026/04/28 13:20:20 by mide-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putui(unsigned int n)
{
	int	ret;

	ret = 0;
	if (n >= 10)
		ret += ft_putui(n / 10);
	ret += ft_putchar((n % 10) + '0');
	return (ret);
}
