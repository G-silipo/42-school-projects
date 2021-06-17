/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilipo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:02:59 by gsilipo           #+#    #+#             */
/*   Updated: 2021/01/19 17:34:08 by gsilipo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int checkchar(char *set, char c)
{
	int i;

	i = 0;
	while(set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return(0);
}

int		get_index(char const *s1, char const *set, int index)
{
	if (index == 0)
	{
		while (checkchar((char *)set, s1[index]) && s1[index])
			index++;
	}
	else
	{
		while (checkchar((char *)set, s1[index]) && index > 0)
			index--;
	}
	return (index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char *st;
	int end;
	int t;
	int start;
	
	if(!s1 || !set)
		return(NULL);
	end = get_index(s1, set, ft_strlen(s1) - 1);
	start = get_index(s1, set, 0);
	t = 0;
	if (end > start)
	{
		if(!(st=(char *)malloc((end - start + 2) * sizeof(char))))
			return(NULL);
	}
	else
	{
		if(!(st=(char *)malloc(sizeof(char))))
			return (NULL);
	}
	while(start <= end)
		st[t++] = s1[start++];
	st[t]= '\0';
	return(st);
}