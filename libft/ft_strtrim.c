/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:42:10 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/03/28 19:56:56 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_search(char const *set, char n)
{
	int	j;

	j = 0;
	while (set[j])
	{
		if (set[j] == n)
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str;
	int		x;

	i = 0;
	while (s1[i] && ft_search(set, s1[i]))
		i++;
	j = ft_strlen(s1);
	while (j > i && ft_search(set, s1[j - 1]))
		j--;
	str = (char *)malloc(j - i + 1);
	if (str == NULL)
		return (NULL);
	x = 0;
	while (i < j)
	{
		str[x] = s1[i];
		i++;
		x++;
	}
	str[x] = '\0';
	return (str);
}
