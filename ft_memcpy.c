/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throdrig <throdrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 19:30:02 by throdrig          #+#    #+#             */
/*   Updated: 2021/08/02 21:53:30 by throdrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	offset;

	if ((!dest && !src))
		return (0);
	offset = 0;
	while (offset < n)
	{
		((unsigned char *)dest)[offset] = ((unsigned char *)src)[offset];
		offset++;
	}
	return (dest);
}
