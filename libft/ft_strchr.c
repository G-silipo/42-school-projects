/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilipo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 16:16:05 by gsilipo           #+#    #+#             */
/*   Updated: 2021/01/17 16:18:18 by gsilipo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *p1;
	unsigned int i;

	i = 0;
	p1 = (char *)s;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return((char *)p1);
		i++;
		p1++;
	}
	if (s[i] == c)
	{
		return((char *)s + i);
	}
	return(NULL);
}	
