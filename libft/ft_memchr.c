/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilipo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:20:35 by gsilipo           #+#    #+#             */
/*   Updated: 2021/01/17 15:24:00 by gsilipo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	unsigned char *p1;
	size_t i;
	unsigned char d;

	d = (unsigned char)c;
	p1 = s;
	i = 0;
	while (n > 0)
	{
		if ( *p1 != d)
		{
			i++;
			p1++;
			n--;
		}
		else
			return ((unsigned char *)s + i);
	}
	return(NULL);
}

