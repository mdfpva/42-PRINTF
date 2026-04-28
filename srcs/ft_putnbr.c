/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mide-fre <mide-fre@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 13:06:30 by mide-fre          #+#    #+#             */
/*   Updated: 2026/04/28 13:14:43 by mide-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putnbr(int nbr)
{
	int		ret;
	long	n;

	ret = 0;
	n = nbr;
	if (n < 0)
	{
		ret += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
		ret += ft_putnbr(n / 10);
	ret += ft_putchar((n % 10) + '0');
	return (ret);
}
