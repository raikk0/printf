/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throdrig <throdrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:24:00 by throdrig          #+#    #+#             */
/*   Updated: 2021/08/03 17:08:55 by throdrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include "limits.h"

int ft_printf(const char*, ...);

void	ft_putnbr_fd(unsigned int n, int fd,  int sign, int *count);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd, int *count);
char	*ft_strdup(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *str);

/* 
** Utils
*/

void	ft_toHexa(unsigned long n, int *count, int aux, char c);
int		ft_writeX(unsigned long n, int *count);
void	ft_printPc(int *count);

#endif