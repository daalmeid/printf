/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:18:43 by daalmeid          #+#    #+#             */
/*   Updated: 2021/11/18 17:00:56 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_printf(char *s)
{
	int	i;

	if (s == 0)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
	return (i);
}