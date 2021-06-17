/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilipo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 16:22:24 by gsilipo           #+#    #+#             */
/*   Updated: 2021/01/17 16:24:35 by gsilipo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t h;
	size_t n;

	h = 0;
	if (ft_strlen(needle) + ft_strlen(haystack) == 0)
	   return((char *)haystack);	
	if (ft_strlen(needle) > ft_strlen(haystack))
		return (NULL);
	if (ft_strlen(needle) == 0)
		return((char *)haystack);
	while (haystack[h] && h < len)
	{
		n = 0;
		while (needle[n] == haystack[h + n] && (n + h) < len)
		{
			if (needle[n + 1] == '\0')
				return ((char*) haystack + h);
			n++;
		}
		h++;
	}
	return (NULL);
}		
