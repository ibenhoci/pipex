/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:18:39 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/04/12 10:28:23 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_words(char const *s, char c)
{
	size_t	i;
	int		res;
	size_t	j;

	i = 0;
	res = 0;
	while (i < ft_strlen(s))
	{
		while (i < ft_strlen(s))
		{
			if (c != s[i])
				break ;
			i++;
		}
		j = i;
		while (j < ft_strlen(s))
		{
			if (c == s[j++])
				break ;
		}
		if (j > i)
			res = res + 1;
		i = j;
	}
	return (res);
}

char	*ft_make_word(char const *s, int *i, char c)
{
	size_t		j;
	int			x;
	static char	buffer[32767];

	while (*i < (int)ft_strlen(s))
	{
		if (c != s[*i])
			break ;
		(*i)++;
	}
	x = 0;
	j = *i;
	while (j < ft_strlen(s))
	{
		if (c == s[j])
			break ;
		buffer[x] = s[j];
		x++;
		j++;
	}
	*i = j;
	buffer[x] = '\0';
	return (buffer);
}

char	**free_split(char **tab, int j, char const *s, char c)
{
	int	i;
	int	len;

	len = ft_words(s, c) - ft_words(s + j, c);
	i = 0;
	tab = tab - len;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		y;
	char	**tab;
	int		size;
	int		i;

	i = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_words(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	while (ft_words(s + i, c))
	{	
		y = i;
		size = ft_strlen(ft_make_word(s, &i, c));
		i = y;
		*tab = (char *)malloc(size + 1);
		if (*tab == NULL)
			return (free_split(tab, i, s, c));
		ft_strlcpy(*tab, ft_make_word(s, &i, c), size + 1);
		tab++;
	}
	*tab = 0;
	tab = tab - ft_words(s, c);
	return (tab);
}
