/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:27:40 by sekeskin          #+#    #+#             */
/*   Updated: 2024/01/09 13:09:07 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int(int number)
{
	int	len;

	len = 0;
	if (number == 0)
		return (ft_putchar('0'));
	if (number == -2147483648)
		return (ft_putstr("-2147483648"));
	if (number < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		len++;
		number *= -1;
	}
	if (number >= 10)
	{
		len += ft_int(number / 10);
		if (len == -1)
			return (-1);
	}
	if (ft_putchar("0123456789"[number % 10]) == -1)
		return (-1);
	return (len + 1);
}

int	ft_unsigned(unsigned int number)
{
	int		len;
	char	*base;

	base = "0123456789";
	len = 0;
	if (number >= 10)
	{
		len = ft_unsigned(number / 10);
		if (len == -1)
			return (-1);
	}
	if (ft_putchar(base[number % 10]) == -1)
		return (-1);
	return (len + 1);
}

int	ft_hex(unsigned int number, char format)
{
	int	len;

	len = 0;
	if (number >= 16)
	{
		len = ft_hex(number / 16, format);
		if (len == -1)
			return (-1);
	}
	if (format == 'X')
	{
		if (ft_putchar("0123456789ABCDEF"[number % 16]) == -1)
			return (-1);
	}
	if (format == 'x')
	{
		if (ft_putchar("0123456789abcdef"[number % 16]) == -1)
			return (-1);
	}
	return (len + 1);
}

int	ft_point(unsigned long int number, int mod)
{
	int	len;

	len = 0;
	if (mod == 1)
	{
		if (ft_putstr("0x") == -1)
			return (-1);
		mod = 0;
		len += 2;
	}
	if (number >= 16)
	{
		len += ft_point(number / 16, mod);
		if (len == -1)
			return (-1);
	}
	if (ft_putchar("0123456789abcdef"[number % 16]) == -1)
		return (-1);
	return (len + 1);
}
