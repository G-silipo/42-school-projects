/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilipo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 12:12:39 by gsilipo           #+#    #+#             */
/*   Updated: 2021/01/20 12:12:41 by gsilipo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_countwords(char const *s, char c)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (s[i] && s[i]	== c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			count++;
		}
		i++;
	}
	if (s[ft_strlen(s) - 1] != c)
		count++;
	return(count);
}

char *ft_mallocs(char const *s, char c)
{
	char *word;
	char const *start;
	char *end;
	int i;
	int count;

	count = 0;
    i = 0;
	start = s;
	while (s[i] && s[i] != c)
	{
		count++;
		i++;
	}
	if (!(word = ((char *)malloc((count + 1) * sizeof(char)))))
		return (NULL);
	end = word;
	while (*start && *start != c)
		*word++ = *start++;
	*word = '\0';
	return (end);
}

char	**ft_split(char const *s, char c)
{	
	char **tmp;
	char **array;

	if (!s || !(array = malloc((ft_countwords(s, c) + 1) * sizeof(char *))))
		return (NULL);
	tmp = array;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			*array++ = ft_mallocs(s, c);
		while (*s && *s != c)
			s++;
	}
	*array = NULL;
	return(tmp);
}