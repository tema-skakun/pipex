/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarkhaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:36:59 by fdarkhaw          #+#    #+#             */
/*   Updated: 2021/10/18 13:37:13 by fdarkhaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ОПИСАНИЕ
toupper() преобразует символ c в заглавный, если это возможно.
Если c - это не unsigned char или равен EOF, поведение упомянутых функций
непредсказуемо.

ВОЗВРАЩАЕМЫЕ ЗНАЧЕНИЯ
Возвращается преобразованный символ или c, если преобразование невозможно.
*/

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int	n = 'c';

	printf("ft	: %d\n", ft_toupper(n));
	printf("c	: %d\n", toupper(n));
	return (0);
}
*/