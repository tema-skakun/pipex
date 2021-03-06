/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarkhaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:42:45 by fdarkhaw          #+#    #+#             */
/*   Updated: 2021/10/15 17:42:56 by fdarkhaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ОПИСАНИЕ
Функция strchr() возвращает указатель на местонахождение первого совпадения с
символом c в строке s.
Здесь, "символ" означает "байт" - эта функция не работает с широкими и
многобайтными символами.

ВОЗВРАЩАЕМЫЕ ЗНАЧЕНИЯ
Функции strchr() возвращают указатель на совпадения с
соответствующим символом, а если символ не найден, то возвращают NULL.
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	sym;

	sym = (char) c;
	while (*s != '\0' && *s != sym)
		s++;
	if (*s == sym)
		return ((char *)s);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int	c = 'o';
	char	*str = "Hello World";

	printf("ft	: %s\n", ft_strchr(str, c));
	printf("c	: %s\n", strchr(str, c));
	return (0);
}
*/