/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:06:59 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/04/05 13:22:01 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(int c)
{
	int	res;

	res = 1;
	while (c > 0)
	{
		res = res * 10;
		c--;
	}
	return (res);
}

int	ft_len(int n)
{
	int				i;
	unsigned int	sauv;

	i = 0;
	if (n < 0)
	{
		sauv = n * (-1);
		i++;
	}
	else
		sauv = n;
	if (n == 0)
		return (1);
	while (sauv > 0)
	{
		sauv = sauv / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				i;
	unsigned int	sauv;
	char			*str;
	int				size;

	i = 0;
	size = ft_len(n);
	str = malloc(size + 1);
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[i++] = '-';
		sauv = n * (-1);
	}
	else
		sauv = n;
	while (i < size)
	{
		str[i] = (sauv / ft_power(size - i - 1)) + '0';
		sauv = sauv % ft_power(size - i - 1);
		i++;
	}
	str[i] = '\0';
	return (str);
}
