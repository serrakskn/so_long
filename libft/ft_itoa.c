/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:08:47 by sekeskin          #+#    #+#             */
/*   Updated: 2023/12/26 12:36:51 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_char(char *str, unsigned int number, long int len)
{
	while (number > 0)
	{
		str[len--] = 48 + (number % 10);
		number /= 10;
	}
	return (str);
}

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	number;
	long	len;

	number = 0;
	len = ft_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len--] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n < 0)
	{
		number = n * -1;
		str[0] = '-';
	}
	else
		number = n;
	str = ft_char(str, number, len);
	return (str);
}
