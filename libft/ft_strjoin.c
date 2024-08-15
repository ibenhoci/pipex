/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:14:35 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/04/03 14:42:52 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*x;

	x = (char *)malloc(ft_strlen(s1) + (ft_strlen(s2) + 1));
	if (x == NULL)
		return (NULL);
	ft_strlcpy(x, s1, ft_strlen(s1) + 1);
	ft_strlcat(x, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (x);
}
