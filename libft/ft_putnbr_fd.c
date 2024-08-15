/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:16:48 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/03/28 16:54:51 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;
	char			c;

	if (n < 0)
	{
		write(fd, "-", 1);
		nbr = n * (-1);
	}
	else
		nbr = n;
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
	else
	{
		c = nbr + '0';
		write(fd, &c, 1);
	}
}
