/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throdrig <throdrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 20:18:15 by throdrig          #+#    #+#             */
/*   Updated: 2021/08/03 17:04:23 by throdrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


int main(void)
{

	char *ptr;
	char *null_str;
	/*int i;

	i = 0;
	while(i < 100){

		printf("%d, %p\n", ptr-(i*1000000), ptr-(i*1000000));
		ft_printf("%d, %p\n", ptr-(i*1000000), ptr-(i*1000000));
		i++;
	}*/

	//printf("x : %x | p: %p \n", ptr-(8000000));
	//ft_printf("x : %x | p: %p \n", ptr-(8000000));
	/*printf("\n[d]\n");
	printf("count: %d\n", ft_printf("%d\n", -123));		// integer
	printf("count: %d\n", printf("%d\n", -123));		// integer

	printf("\n[s]\n");
	printf("count: %d\n", ft_printf("%s\n", null_str));	// string
	printf("count: %d\n", printf("%s\n", null_str));	// string

	printf("\n[c]\n");
	printf("count: %d\n", ft_printf("%c|\n", '\0'));		// %c print a single character.
	printf("count: %d\n", printf("%c|\n", '\0'));		// %c print a single character.

	printf("\n[p]\n");
	printf("count: %d\n", ft_printf("printf: %p\n", LONG_MAX));		// %p pointer in hexa
	printf("count: %d\n", printf("printf: %p\n", LONG_MAX));		// %p pointer in hexa

	printf("\n[i]\n");
	ft_printf("ft_printf: %i\n", 0x42);		// %i print an integer in base 10.
	printf("printf: %i\n\n", 0x42);		// %i print an integer in base 10.

	printf("\n[u]\n");
	ft_printf("ft_printf: %u\n", -1000);		// %u print an unsigned decimal (base 10) number.
	printf("ft_printf: %u\n\n", -1000);		// %u print an unsigned decimal (base 10) number.

	printf("\n[x]\n");
	printf("count: %d\n", ft_printf("%x\n", LONG_MAX));		// %x print a number in hexadecimal (base 16).
	printf("count: %d\n", printf("%x\n", LONG_MAX));		// %x print a number in hexadecimal (base 16).

	printf("\n[X]\n");
	printf("count: %d\n", ft_printf("%X\n", 10));		// %x print a number in hexadecimal (base 16).
	printf("count: %d\n", printf("%X\n", 10));		// %x print a number in hexadecimal (base 16).

	printf("\n[%%]\n");
	ft_printf("ft_printf: %%\n");			// %% print % sign.
	printf("printf: %%\n");			// %% print % sign.
	*/
	ft_printf("|%-1c|\n", '0');
	printf("|%-1c|\n", '0');

	return(0);
}