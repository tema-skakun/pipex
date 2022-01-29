/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarkhaw <fdarkhaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:30:54 by fdarkhaw          #+#    #+#             */
/*   Updated: 2022/01/26 08:06:42 by fdarkhaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_errors(int i)
{
	if (i == 1)
	{
		ft_putendl_fd("Incorrect number of arguments", 2);
		ft_putendl_fd("Instance: ./pipex file1 \"cmd1\" \"cmd2\" file2", 2);
	}
	else if (i == 2)
		ft_putendl_fd("cmd1 or cmd2 does not exist", 2);
	else if (i == 3)
		ft_putendl_fd("file1 does not exist or is closed for reading", 2);
	else if (i == 4)
		perror("Error");
	exit (0);
	return (1);
}

void	run_cmd(char *av, char **envp)
{
	char	*path;
	char	**cmd;

	cmd = ft_split(av, ' ');
	if (cmd == NULL)
		ft_errors(4);
	path = search_path(envp, cmd[0]);
	if (path == NULL)
	{
		free(path);
		ft_free(cmd);
		ft_errors(4);
	}
	if (execve(path, cmd, NULL) == -1)
	{
		free(path);
		ft_free(cmd);
		ft_errors(4);
	}
	free(path);
	ft_free(cmd);
}

void	ft_parent(int *fd, char **argv, char **envp)
{
	int	out;

	out = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (out < 0)
		ft_errors(4);
	if (dup2(fd[0], 0) < 0)
		ft_errors(4);
	close(fd[1]);
	if (dup2(out, 1) < 0)
		ft_errors(4);
	run_cmd(argv[3], envp);
}

void	ft_child(int *fd, char **argv, char **envp)
{
	int	in;

	in = open(argv[1], O_RDONLY);
	if (in < 0)
		ft_errors(4);
	if (dup2(fd[1], 1) < 0)
		ft_errors(4);
	close(fd[0]);
	if (dup2(in, 0) < 0)
		ft_errors(4);
	run_cmd(argv[2], envp);
}

void	pipex(char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;
	pid_t	wt;

	if (pipe(fd) == -1)
		ft_errors(4);
	pid = fork();
	if (pid == -1)
		ft_errors(4);
	else if (pid == 0)
		ft_child(fd, argv, envp);
	else if (pid > 0)
	{
		ft_parent(fd, argv, envp);
		wt = waitpid(pid, NULL, 0);
		if (wt == -1)
			ft_errors(4);
		close(fd[0]);
		close(fd[1]);
	}
}
