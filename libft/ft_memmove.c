/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilipo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:15:45 by gsilipo           #+#    #+#             */
/*   Updated: 2021/01/17 15:18:52 by gsilipo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	unsigned char *ds;
	unsigned char *sr;
	size_t i;

	ds = (unsigned char *) str1;
	sr = (unsigned char *) str2;

	if (!ds && !sr)
		return(NULL);
	if (str2 >= str1)
	{
		i = 0;
		while (i < n)
		{
			ds[i] = sr[i];
			i++;
		}
	}
	else
	{
		while ( n > 0)
		{
			n--;
			ds[n] = sr[n];
		}
	}
	return(ds);
}
