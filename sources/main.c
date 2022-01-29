/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarkhaw <fdarkhaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:51:33 by fdarkhaw          #+#    #+#             */
/*   Updated: 2022/01/26 06:36:25 by fdarkhaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	if (check_input(argc, argv, envp))
	{
		exit(0);
		return (1);
	}
	pipex(argv, envp);
	exit(0);
	return (0);
}
