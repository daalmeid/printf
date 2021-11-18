/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:08:29 by daalmeid          #+#    #+#             */
/*   Updated: 2021/11/18 16:58:37 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>

int		ft_putnbr_base(int nbr, char *base, char *fl);
int		ft_rule_out(char *base);
int		ft_putnbr_un(unsigned int nbr, char *fl);
int		ft_putnbr_ptr(unsigned long long nbr, char *fl);
void	ft_check_fl(va_list *arg, char *fl);
void	ft_bzero(void *s, size_t n);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_putstr_printf(char *s);
int		ft_putnbr_printf(int nbr);
int		ft_printf(const char *s, ...);

#endif