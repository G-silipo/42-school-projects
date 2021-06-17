/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilipo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:08:02 by gsilipo           #+#    #+#             */
/*   Updated: 2021/01/12 15:24:08 by gsilipo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while ( i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		if(((unsigned char *)src)[i] == (unsigned char)c)
			return(dst + i + 1);
		i++;
	}
	return(0);
}