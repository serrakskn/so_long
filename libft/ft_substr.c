/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:47:00 by sekeskin          #+#    #+#             */
/*   Updated: 2024/05/11 16:42:11 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*src;

	src = (char *)s;
	if (!src)
		return (0);
	if (start >= ft_strlen(s))
	{
		substr = (char *)malloc(sizeof(char));
		if (!substr)
			return (0);
		*substr = '\0';
	}
	else
	{
		if ((ft_strlen(s) - start) < len)
			len = ft_strlen(s) - start;
		substr = (char *)malloc(sizeof(char) * (len + 1));
		if (!substr)
			return (0);
		ft_strlcpy(substr, (char *)(s + start), len + 1);
	}
	return (substr);
}
