/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilipo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 16:18:40 by gsilipo           #+#    #+#             */
/*   Updated: 2021/01/17 16:21:20 by gsilipo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *p1;
	unsigned int len;

	len = ft_strlen(s);
	p1 = (char *) s;
	if (s[len] == c)
		return((char *)s + len);
	while (len > 0)
	{
		len--;
		if (s[len] == (unsigned char)c)
			return((char *)s + len);
	}
	return(NULL);
}	
