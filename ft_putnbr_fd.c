/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throdrig <throdrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:00:42 by throdrig          #+#    #+#             */
/*   Updated: 2021/08/02 22:14:42 by throdrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_fd(unsigned int n, int fd, int sign, int *count)
{
	unsigned int	nbr;

	
	if (sign)
	{
		if((signed int)n < 0){
			ft_putchar_fd('-', fd);
			nbr = (unsigned int)n * -1;
			(*count)++;
		}
		else
			nbr = (unsigned int)n;
	}else{
		nbr = (unsigned int)n;
	}
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd, sign, count);
	ft_putchar_fd((char)(nbr % 10) + 48, fd);
	(*count)++;
}
