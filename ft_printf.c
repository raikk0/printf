/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throdrig <throdrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 20:27:57 by throdrig          #+#    #+#             */
/*   Updated: 2021/08/02 22:45:32 by throdrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void ft_toHexa(unsigned int n, int *count, int aux)
{
	int q;

	q = n / 16;
	if(q > 0)
	{
		n = n % 16;
		
		if( n < 10)
			n = n + '0';
		else 
			n = (n - 10) + aux;
		ft_toHexa(q, count, aux);
		write(1, &n, 1);
	}
	if(q == 0){
		if(n < 10)
			n = n + '0';
		else
			n = (n - 10) + aux;
		write(1, &n, 1);
	}
	(*count)++;
}

static void ft_getArg(va_list args, char c, int *count)
{
	if (c == 'd' || c == 'i') // inteiro
		ft_putnbr_fd(va_arg(args, int), 1, 1, count);
	else if(c == 's') // string
		ft_putstr_fd(va_arg(args, char*), 1, count);
	else if(c == 'c'){ // char
		(*count)++;
		ft_putchar_fd(va_arg(args, int), 1);
	}
	else if(c == 'p'){
		write(1, "0x", 2);
		*count += 2;
		ft_toHexa(va_arg(args, int), count, 97);
	}
	else if (c == 'u') 
		ft_putnbr_fd(va_arg(args, unsigned int), 1, 0, count);
	else if(c == 'x')
		ft_toHexa(va_arg(args, int), count, 97);
	else if(c == 'X')
		ft_toHexa(va_arg(args, int), count, 65);
	else if(c == '%'){
		(*count)++;
		write(1, "%", 1);
	}
}

int ft_printf(const char *strdata, ...)
{
	char *ptrdata;
	int count;
	va_list args;
	int i;

	count = 0;
	ptrdata = ft_strdup(strdata);
	va_start(args, strdata);
	i = 0;
	while(ptrdata[i])
	{
		if(ptrdata[i] == '%')
		{
			ft_getArg(args, ptrdata[i+1], &count);
			i++;
		}else{
			ft_putchar_fd(ptrdata[i], 1);
			count++;
		}
		i++;
	}

	free(ptrdata);
	va_end(args);
	return (count);
}