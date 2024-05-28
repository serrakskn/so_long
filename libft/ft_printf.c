/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:55:41 by sekeskin          #+#    #+#             */
/*   Updated: 2024/01/15 18:38:08 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		if (ft_putstr("(null)") == -1)
			return (-1);
		return (6);
	}
	while (str[i])
	{
		if (ft_putchar(str[i++]) == -1)
			return (-1);
	}
	return (i);
}

static int	ft_check(char str)
{
	return (str == 'c' || str == 'd' || str == 'i' || str == 'u' || str == '%'
		|| str == 's' || str == 'x' || str == 'X' || str == 'p');
}

static int	ft_format(va_list *arg, char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg((*arg), int)));
	else if (format == 's')
		return (ft_putstr(va_arg((*arg), char *)));
	else if (format == 'p')
		return (ft_point(va_arg((*arg), unsigned long), 1));
	else if (format == 'd' || format == 'i')
		return (ft_int(va_arg((*arg), int)));
	else if (format == 'u')
		return (ft_unsigned(va_arg((*arg), unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_hex(va_arg((*arg), unsigned int), format));
	else if (format == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	arg;

	i = -1;
	len = 0;
	va_start(arg, format);
	while (format[++i])
	{
		if (format[i] == '%' && ft_check(format[i + 1]))
		{
			len += ft_format(&arg, format[++i]);
			if (len == -1)
				return (-1);
			len--;
		}
		else if (ft_putchar(format[i]) == -1)
			return (-1);
		len++;
	}
	va_end(arg);
	return (len);
}
