/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilipo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:30:16 by gsilipo           #+#    #+#             */
/*   Updated: 2021/01/19 16:34:13 by gsilipo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *sc;
	int i;
	int a;
	int t;

	if(!s1 || !s2)
		return(NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(sc=(char *)malloc((i + 1) * sizeof(char))))
		return(NULL);
	t = 0;
	a = 0;
	while (s1[a])
		sc[t++] = s1[a++];
	a = 0;
	while (s2[a])
	{
		sc[t] = s2[a];
		a++;
		t++;
	}
	sc[t] = '\0';
	return(sc);
}
