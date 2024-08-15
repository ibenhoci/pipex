/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:56:25 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/04/03 14:45:29 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int					i;
	unsigned int		j;
	char				*str;

	j = 0;
	i = ft_strlen(s);
	str = (char *)malloc(i + 1);
	if (str == NULL)
		return (NULL);
	while (j < ft_strlen(s))
	{
		str[j] = f(j, s[j]);
		j++;
	}
	str[j] = '\0';
	return (str);
}
