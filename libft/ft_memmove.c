/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:29:37 by sekeskin          #+#    #+#             */
/*   Updated: 2024/05/11 16:42:21 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (dst == src)
		return (dst);
	else if (d > s)
	{
		while (len > 0)
		{
			len--;
			*(d + len) = *(s + len);
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (d);
}
