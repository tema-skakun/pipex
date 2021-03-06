/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarkhaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:36:25 by fdarkhaw          #+#    #+#             */
/*   Updated: 2021/10/15 17:36:30 by fdarkhaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ОПИСАНИЕ
Данные функции проверяют, попадает ли символ c (который должен иметь значение
unsigned char или EOF) в определенный класс символов, существующих в текущем
окружении.
Проверяет символ на принадлежность к алфавитным символам; в стандартном
окружении "C" это эквивалентно (isupper(c) || islower(c)). В некоторых
системах могут существовать дополнительные символы, для которых isalpha()
верно, т.е. буквы могут не находиться ни в верхнем, ни в нижнем регистре.

ВОЗВРАЩАЕМЫЕ ЗНАЧЕНИЯ
Возвращаются ненулевые значения, если проверяемый символ c попадает в
соответствующий класс символов, в противном случае возвращается ноль. 
*/

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int	n = 50;

	printf("ft	: %d\n", ft_isalpha(n));
	printf("c	: %d\n", isalpha(n));
	return (0);
}
*/