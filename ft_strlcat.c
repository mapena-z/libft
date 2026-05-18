/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapena-z <mapena-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 15:48:23 by mapena-z          #+#    #+#             */
/*   Updated: 2026/05/18 17:42:29 by mapena-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(const char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (dst[len] != '\0' && len < size)
		len++;
	if (size <= len)
		return (len + ft_len(src));
	while (i + len < size - 1 && src[i] != '\0')
	{
		dst[i + len] = src[i];
		i++;
	}
	dst[i + len] = '\0';
	return (len + ft_len(src));
}
