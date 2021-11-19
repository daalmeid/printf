/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:36:24 by daalmeid          #+#    #+#             */
/*   Updated: 2021/11/19 14:19:26 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	ft_check_fl(va_list *arg, char *fl)
{
	int		i;
	va_list	arg2;

	va_copy(arg2, *arg);
	i = va_arg(arg2, int);
	if (i > 0 && ft_strchr(fl, ' '))
		ft_putchar_fd(' ', 1);
	else if (i > 0 && ft_strchr(fl, '+'))
		ft_putchar_fd('+', 1);
	va_end(arg2);
}
