/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilipo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:07:07 by gsilipo           #+#    #+#             */
/*   Updated: 2021/01/17 15:08:55 by gsilipo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char *str;
	unsigned char *d;

	str = src;
	d = dest;
	if (!d && !str )
		return(NULL);
	while (n > 0)
	{
		*d = *str;
		n--;
		d++;
		str++;
	}
	return(dest);
}
