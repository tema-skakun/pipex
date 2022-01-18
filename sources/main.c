/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarkhaw <fdarkhaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:51:33 by fdarkhaw          #+#    #+#             */
/*   Updated: 2022/01/18 16:28:34 by fdarkhaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

#include <stdio.h>

// int	main(int argc, char **argv)//, char **env)
// {
// 	int		in;
// 	int		out;
// 	int		j;
// 	int		f;
// 	// char	**str;

// 	j = argc;
// 	in = open("infile", O_RDONLY);
// 	dup2(in, 0);// дублирует потоки, позволяет поменять стандартный ввод (0) на in
// 	// execve будет брать информацию НЕ из стандартного ввода, а из файла infile
// 	f = fork();// раздваивает процесс: в родительском процессе f > 0, в дочернем - f == 0
// 	// если f < 0 - это ошибка - нужно обрабатывать (так же и у dup, pipe)
// 	// if (f == 0)
// 	// str = ft_split(*argv, ' ');
// 	// printf("str = %s\n", str[0]);
// 	if (execve("/bin/grep", &argv[2], NULL) == -1)// проблема: всё, что находится ниже не исполнится
// 	// решается через fork и wait
// 		perror("Could not execute execve");
// 	printf("Oops\n");
// 	wait(&f);// ждёт смерти дочернего процесса
// 	// if (access(env[7], X_OK) == -1)
// 	// 	printf("No file");
// 	//execve("/bin/grep", ft_split(argv[2], ' ') , &env[7]);// всё, что находится ниже не исполнится
// 	out = open("outfile", O_WRONLY | O_TRUNC | O_CREAT, 0777);// задали/создали файл на ввод/запись
// 	// O_TRUNC - почистит файл, если в нём есть содержимое
// 	// O_CREAT - если файла нет - создаст
// 	// 0777 - разрешения для файла (нужны другие)
// 	dup2(out, 1);// теперь при вызове 1 мы будем обращаться к out
// 	return (0);
// }

int	main(void)
{
	int		in;
	int		out;
	char	cmd[] = "/usr/bin/grep";
	char	*argv[] = {"grep", "a", NULL};
	char	*env[] = {NULL};

	in = open("infile", O_RDONLY);
	dup2(in, 0);
	out = open("outfile", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	dup2(out, 1);
	printf("Start of execve call %s:\n", cmd);
	printf("===========================================\n");
	if (execve(cmd, argv, env) == -1)
		perror("Could not execute execve");
	printf("Oops\n");
	return (0);
}

// int	main(int argc, char **argv, char **env)
// {
// 	int	i;

// 	i = 0;
// 	printf("argc = %d\n", argc);
// 	while (argv[i])
// 	{
// 		printf("argv[%d] = %s\n", i, argv[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while (env[i])
// 	{
// 		printf("env[%d] = %s\n", i, env[i]);
// 		i++;
// 	}
// 	return (0);
// }

// #include <stdio.h>
// #include <string.h>
// #include <unistd.h>

// int	main(int argc, char *argv[])
// {
//     if (argc > 1)
// 	{
//         char	*word = strtok(argv[1], " ");
//         char	path[128] = "/bin/";
//         strcat (path, word);

//         char * newenvp[] = { NULL };
//         char * newargv[] = { path, NULL };
//         printf ("[%s]\n", path);
//         int ret = execve (path, newargv, newenvp);
//         if (ret == -1)
// 		    perror("execve error");
//     }
//     return 0;
// }