/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilipo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 16:12:40 by gsilipo           #+#    #+#             */
/*   Updated: 2021/01/17 16:15:22 by gsilipo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t x;

	i = 0;
	x = ft_strlen(dst);
	while(src[i] != '\0' && i + x + 1 < dstsize )
	{
		dst[x + i] = src[i];
		i++;
	}
	dst[x + i] = 0;
	if (dstsize < x)
		return (ft_strlen(src) + dstsize);
	return (ft_strlen(src) + x);
}
