/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilipo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:00:05 by gsilipo           #+#    #+#             */
/*   Updated: 2021/01/19 15:07:41 by gsilipo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *sb;
	unsigned int i;

	i = 0;
	if (!(sb =(char *)malloc((len + 1) * sizeof(char))))
		return(NULL);
	while (s && start < ft_strlen(s) && len > 0)
	{
		sb[i] = s[start];
		i++;
		start++;
		len--;
	}
	sb[i] = '\0';
	return(sb);
}
