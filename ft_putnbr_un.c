/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_un.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:02:06 by daalmeid          #+#    #+#             */
/*   Updated: 2021/11/18 17:44:48 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static void	check_putnbr_un(unsigned int nbr, char *fl)
{
	if (nbr > 9)
	{	
		check_putnbr_un(nbr / 10, fl);
	}
	if (nbr < 9)
		ft_putchar_fd(nbr + '0', 1);
	else
		ft_putchar_fd(nbr % 10 + '0', 1);
}

int	ft_putnbr_un(unsigned int nbr, char *fl)
{
	int	i;
	int	j;

	i = nbr;
	j = 1;
	while (i > 9)
	{
		i /= 10;
		j++;
	}
	if (nbr == 0)
		ft_putchar_fd(nbr + '0', 1);
	else
		check_putnbr_un(nbr, fl);
	return (j);
}