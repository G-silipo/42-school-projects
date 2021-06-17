/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilipo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:21:48 by gsilipo           #+#    #+#             */
/*   Updated: 2021/01/17 17:24:03 by gsilipo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int i;
	char *p1;
	int n;

	i = 0;
	n = 0;
	while(s1[i])
		i++;
	if (!(p1 = ((char *) malloc((i + 1) * sizeof(char)))))
		return (NULL);
	while(s1[n])
	{
		p1[n] = s1[n];
		n++;
	}
	p1[i] = '\0';
	return((char *)p1);
}
