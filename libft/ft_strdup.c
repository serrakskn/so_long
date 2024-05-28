/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:50:24 by sekeskin          #+#    #+#             */
/*   Updated: 2024/05/11 16:41:44 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	l;
	char	*str;

	l = ft_strlen(s1);
	str = (char *)malloc((l + 1) * sizeof(*s1));
	if (!str)
		return (0);
	ft_memcpy(str, s1, l + 1);
	return (str);
}
