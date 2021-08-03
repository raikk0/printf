/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throdrig <throdrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 20:27:57 by throdrig          #+#    #+#             */
/*   Updated: 2021/08/03 17:03:53 by throdrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_getArg(va_list args, char c, int *count)
{
	unsigned long	wr;

	if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(args, int), 1, 1, count);
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1, count);
	else if (c == 'c')
	{
		(*count)++;
		ft_putchar_fd(va_arg(args, int), 1);
	}
	else if (c == 'p')
	{
		wr = va_arg(args, long);
		if (ft_writeX(wr, count))
			ft_toHexa(wr, count, 97, c);
	}
	else if (c == 'u')
		ft_putnbr_fd(va_arg(args, unsigned int), 1, 0, count);
	else if (c == 'x')
		ft_toHexa(va_arg(args, int), count, 97, c);
	else if (c == 'X')
		ft_toHexa(va_arg(args, int), count, 65, c);
	else if (c == '%')
		ft_printPc(count);
}

int	ft_printf(const char *strdata, ...)
{
	char	*ptrdata;
	int		count;
	va_list	args;
	int		i;

	count = 0;
	ptrdata = ft_strdup(strdata);
	va_start(args, strdata);
	i = 0;
	while (ptrdata[i])
	{
		if (ptrdata[i] == '%')
		{
			ft_getArg(args, ptrdata[i++ + 1], &count);
		}
		else
		{
			ft_putchar_fd(ptrdata[i], 1);
			count++;
		}
		i++;
	}
	free(ptrdata);
	va_end(args);
	return (count);
}
