/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:30:28 by daalmeid          #+#    #+#             */
/*   Updated: 2021/11/19 16:39:20 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

static int	conv_select(char c, va_list *args)
{
	int	ret;

	ret = 0;
	if ((c == 'c' || c == 'C') && !ret++)
		ft_putchar_fd(va_arg(*args, int), 1);
	else if (c == 's')
		ret = ft_putstr_printf(va_arg(*args, char *));
	else if (c == 'd' || c == 'D' || c == 'i')
		ret = ft_putnbr_printf(va_arg(*args, int));
	else if (c == 'u' || c == 'U')
		ret = ft_putnbr_un(va_arg(*args, unsigned int));
	else if (c == 'x')
		ret = ft_putnbr_base(va_arg(*args, int), "0123456789abcdef");
	else if (c == 'X')
		ret = ft_putnbr_base(va_arg(*args, int), "0123456789ABCDEF");
	else if (c == '%' && !ret++)
		ft_putchar_fd('%', 1);
	else if (c == 'p')
		ret = ft_putnbr_ptr(va_arg(*args, long long), "0123456789abcdef");
	return (ret);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	va_list	*ptr_lst;
	int		i;
	int		j;

	va_start(args, s);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '%')
		{	
			ft_putchar_fd(s[i++], 1);
			j++;
		}
		else if (s[i++] == '%')
		{
			if (!(ft_isalpha(s[i])) && s[i] != '%')
				break ;
			ptr_lst = &args;
			j += conv_select(s[i++], ptr_lst);
		}
	}
	va_end(args);
	return (j);
}
/*
int	main(void)
{
	char	*s;
	int		i;
	char	c;
	char	*str;
	
	i = 15;
	c = 'a';
	str = "Dario";
	s = str;
	ft_printf("i: %x and s: %p and c: %c and str: %s, end\n", i, s, c, str);
	printf("i: %x and s: %p and c: %c and str: %s, end\n", i, s, c, str);
	return (0);
}*/