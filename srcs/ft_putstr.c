/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mide-fre <mide-fre@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:17:54 by mide-fre          #+#    #+#             */
/*   Updated: 2026/04/28 19:23:48 by mide-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putstr(char *s)
{
	int	ret;

	if (!s)
		return (ft_putstr("(null)"));
	ret = 0;
	while (*s)
		ret += ft_putchar(*s++);
	return (ret);
}
