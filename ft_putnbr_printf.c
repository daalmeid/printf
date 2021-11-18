/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:23:53 by daalmeid          #+#    #+#             */
/*   Updated: 2021/11/18 17:29:03 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_putnbr_printf(int nbr)
{
	int	i;
	int	j;

	i = nbr;
	j = 1;
	while (i > 9 || i < -9)
	{
		i /= 10;
		j++;
	}
	if (nbr < 0)
		j++;
	ft_putnbr_fd(nbr, 1);
	return (j);
}

/*int	main(void)
{
	int	n;
	int	fd;

	n = 21474836;
	fd = 1;
	ft_putnbr_fd(n, fd);
	return (0);
}*/