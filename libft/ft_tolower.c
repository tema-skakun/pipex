/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarkhaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:46:49 by fdarkhaw          #+#    #+#             */
/*   Updated: 2021/10/15 17:47:21 by fdarkhaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ОПИСАНИЕ
tolower() преобразует символ c в строчной, если это возможно.
Если c - это не unsigned char или равен EOF, поведение упомянутых функций
непредсказуемо.

ВОЗВРАЩАЕМЫЕ ЗНАЧЕНИЯ
Возвращается преобразованный символ или c, если преобразование невозможно.
*/

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int	n = 'A';

	printf("ft	: %d\n", ft_tolower(n));
	printf("c	: %d\n", tolower(n));
	return (0);
}
*/