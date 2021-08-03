/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throdrig <throdrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 00:46:38 by throdrig          #+#    #+#             */
/*   Updated: 2021/08/02 22:24:43 by throdrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstr_fd(char *s, int fd, int *count)
{
	if(s){
		write(fd, &*s, ft_strlen(s));
		*count += ft_strlen(s);
	}else{
		write(fd, "(null)", 6);
		*count += 6;
	}
}
