/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:00:04 by daalmeid          #+#    #+#             */
/*   Updated: 2021/11/18 17:00:13 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

static char	*prep_flags(char *ret, char fl)
{
	if (fl == '#' || fl == ' ' || fl == '+' || fl == '-' || fl == '0')
	{
		if (!(ft_strchr(ret, fl)))
			ret[ft_strlen(ret)] = fl;
		return (ret);
	}
	return (NULL);
}

static char	*flag_conflict(char fl[])
{
	if (ft_strchr(fl, '+') && ft_strchr(fl, ' '))
		return (NULL);
	else if (ft_strchr(fl, '-') && ft_strchr(fl, '0'))
		return (NULL);
	return (fl);
}

static char	*check_flags(char *ptr, char ret[])
{
	while (!(ft_isalpha(*ptr)) && *ptr != '\0' && *ptr != '%')
	{
		if (*ptr == '.' || (ft_isdigit(*ptr) && *ptr != '0'))
			break;	
		if(!prep_flags(ret, *ptr))
			return (NULL);
		ptr++;
	}
	if(!flag_conflict(ret))
		return (NULL);
	if (*ptr == '.')
		ret[ft_strlen(ret)] = *ptr++;
	while (ft_isdigit(*ptr))
	{
		ret[ft_strlen(ret)] = *ptr;
		ptr++;
	}
	if (*ptr == '.' && !(ft_strchr(ret, '.')))
		ret[ft_strlen(ret)] = *ptr++;
	else if (*ptr == '.' && ft_strchr(ret, '.'))
		return (NULL);
	while (ft_isdigit(*ptr))
	{
		ret[ft_strlen(ret)] = *ptr;
		ptr++;
	}
	if (!(ft_isalpha(*ptr)) && *ptr != '%')
		return (NULL);
	else
		ret[ft_strlen(ret)] = *ptr;
	return (ret);
}

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
	{	
		ft_check_fl(args, fl);
		ret = ft_putnbr_printf(va_arg(*args, int));
	}
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
	char	*ptr;
	char	*fl;
	char	ret[30];

	va_start(args, s);
	i = 0;
	k = 0;
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
			j = i;
			while (!(ft_isalpha(s[i])) && s[i] != '\0' && s[i] != '%')
				i++;
			ptr = ft_substr(s, j, i + 1 - j);
			if (!ptr)
				return (0);
			ft_bzero(ret, 30);
			fl = check_flags(ptr, ret);
			free (ptr);
			ptr_lst = &args;
			j = conv_select(fl[ft_strlen(fl) - 1], ptr_lst, fl);
			k += j;
		}
		i++;
	}
	va_end(args);
	return (k);
}

int	main(void)
{
	void	*s;
	int		i;
	char	c;
	char	*str;
	
	i = -2147483640;
	s = &i;
	c = 'a';
	str = "Dario";
	ft_printf("Value of i: %x and s: %p and c: %-c and str: %s, end\n", i, s, c, str);
	printf("Value of i: %x and s: %p and c: %-c and str: %s, end\n", i, s, c, str);
	return (0);
}