/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarkhaw <fdarkhaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:03:16 by fdarkhaw          #+#    #+#             */
/*   Updated: 2022/02/22 15:00:59 by fdarkhaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **p_str)
{
	int	i;

	i = 0;
	if (p_str != NULL)
	{
		while (p_str[i])
			free(p_str[i++]);
		free(p_str);
	}
}

char	**paths(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_memcmp(envp[i], "PATH=", 5))
			return (ft_split(envp[i] + 5, ':'));
		i++;
	}
	return (NULL);
}

char	*search_path(char **envp, char *cmd)
{
	int		i;
	char	*path;
	char	**env_paths;

	env_paths = paths(envp);
	if (env_paths == NULL)
		ft_errors(4);
	i = 0;
	while (env_paths[i])
	{
		path = ft_strjoin(env_paths[i], "/", 0);
		path = ft_strjoin(path, cmd, 1);
		if (access(path, F_OK) == 0)
		{
			ft_free(env_paths);
			return (path);
		}
		free(path);
		i++;
	}
	ft_free(env_paths);
	return (NULL);
}

char	**search_cmd(char *av)
{
	char	**cmd;

	cmd = ft_split(av, ' ');
	if (cmd == NULL)
	{
		ft_free(cmd);
		ft_errors(4);
	}
	return (cmd);
}

int	check_input(int argc, char **argv, char **envp)
{
	char	**cmd1;
	char	**cmd2;
	char	*env_path1;
	char	*env_path2;

	if (argc != 5)
		ft_errors(1);
	cmd1 = search_cmd(argv[2]);
	cmd2 = search_cmd(argv[3]);
	env_path1 = search_path(envp, cmd1[0]);
	env_path2 = search_path(envp, cmd2[0]);
	ft_free(cmd1);
	ft_free(cmd2);
	if (access(env_path1, F_OK) != 0 || access(env_path2, F_OK) != 0)
	{
		free(env_path1);
		free(env_path2);
		ft_errors(2);
	}
	if (access(argv[1], F_OK | R_OK) != 0)
		ft_errors(3);
	return (0);
}
