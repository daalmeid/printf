/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:30:28 by daalmeid          #+#    #+#             */
/*   Updated: 2021/11/18 17:29:22 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

static int	conv_select(char c, va_list *args, char *fl)
{
	int	ret;

	ret = 0;
	if (c == 'c' || c == 'C')
	{	
		ft_putchar_fd(va_arg(*args, int), 1);
		ret = 1;
	}
	else if (c == 's')
		ret = ft_putstr_printf(va_arg(*args, char *));
	else if (c == 'd' || c == 'D' || c == 'i')
		ret = ft_putnbr_printf(va_arg(*args, int));
	else if (c == 'u' || c == 'U')
		ret = ft_putnbr_un(va_arg(*args, unsigned int), fl);
	else if (c == 'x')
		ret = ft_putnbr_base(va_arg(*args, int), "0123456789abcdef", fl);
	else if (c == 'X')
		ret = ft_putnbr_base(va_arg(*args, int), "0123456789ABCDEF", fl);
	else if (c == '%')
	{	
		ft_putchar_fd('%', 1);
		ret = 1;
	}
	else if (c == 'p')
	{	
		ft_putstr_fd("0x", 1);
		ret = ft_putnbr_ptr(va_arg(*args, unsigned long long), "0123456789abcdef");
	}
	return (ret);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	va_list	*ptr_lst;
	int		i;
	int		j;
	int		k;
	char	*fl;

	va_start(args, s);
	i = 0;
	j = 0;
	k = 0;
	fl = "";
	while(s[i] != '\0')
	{
		if (s[i] != '%')
		{	
			ft_putchar_fd(s[i], 1);
			k++;
		}
		if (s[i] == '%')
		{
			i++;
			if (!(ft_isalpha(s[i])) && s[i] != '%')
				break ;
			ptr_lst = &args;
			j = conv_select(s[i], ptr_lst, fl);
			k += j;
		}
		i++;
	}
	va_end(args);
	return (k);
}
/*
int	main(void)
{
	void	*s;
	int		i;
	char	c;
	char	*str;
	
	i = -9;
	s = &i;
	c = 'a';
	str = "Dario";
	ft_printf("Value of i: %d and s: %p and c: %c and str: %s, end\n", -1, s, c, str);
	printf("Value of i: %d and s: %p and c: %-c and str: %s, end\n", -1, s, c, str);
	return (0);
}*/
