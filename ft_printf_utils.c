/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throdrig <throdrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 17:03:37 by throdrig          #+#    #+#             */
/*   Updated: 2021/08/03 17:09:05 by throdrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_writeX(unsigned long n, int *count)
{
	if (n != 0)
	{
		write(1, "0x", 2);
		*count += 2;
		return (1);
	}
	else
	{
		write(1, "(nil)", 5);
		*count += 5;
		return (0);
	}
}

void	ft_toHexa(unsigned long n, int *count, int aux, char c)
{
	unsigned long int	q;

	if (c == 'x' || c == 'X')
		n = (unsigned int) n;
	q = n / 16;
	if (q > 0)
	{
		n = n % 16;
		if (n < 10)
			n = n + '0';
		else
			n = (n - 10) + aux;
		ft_toHexa(q, count, aux, c);
		write(1, &n, 1);
	}
	if (q == 0)
	{
		if (n < 10)
			n = n + '0';
		else
			n = (n - 10) + aux;
		write(1, &n, 1);
	}
	(*count)++;
}

void	ft_printPc(int *count)
{
	(*count)++;
	write(1, "%", 1);
}