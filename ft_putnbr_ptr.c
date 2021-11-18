/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:57:49 by daalmeid          #+#    #+#             */
/*   Updated: 2021/11/18 17:00:45 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putnbr_ptr(unsigned long long nbr, char *base)
{
	if (nbr > 0)
		ft_putnbr_ptr(nbr / 16, base);
	if (nbr != 0)
		write(1, &(base[nbr % 16]), 1);
	return (14);
}
