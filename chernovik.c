#include "../includes/pipex.h"

#include <stdio.h>

int	main(int argc, char **argv)//, char **env)
{
	int		in;
	int		out;
	int		j;
	int		f;
	char	**str;

	j = argc;
	in = open("infile", O_RDONLY);
//	dup2(in, 0);// дублирует потоки, позволяет поменять стандартный ввод (0) на in
	// execve будет брать информацию не из стандартного ввода, а из файла infile
	f = fork();// раздваивает процесс: в родительском процессе f > 0, в дочернем - f == 0
	// если f < 0 - это ошибка - нужно обрабатывать (так же и у dup, pipe)
	// if (f == 0)
	str = ft_split(argv[2], ' ');
	if (execve("/bin/grep1", str, NULL) == -1)// проблема: всё, что находится ниже не исполнится
	// решается через fork и wait
		perror("Could not execute execve");
	printf("Oops");
	wait(&f);// ждёт смерти дочернего процесса
	// if (access(env[7], X_OK) == -1)
	// 	printf("No file");
	//execve("/bin/grep", ft_split(argv[2], ' ') , &env[7]);// всё, что находится ниже не исполнится
	out = open("outfile", O_WRONLY | O_TRUNC | O_CREAT, 0777);// задали/создали файл на ввод/запись
	// O_TRUNC - почистит файл, если в нём есть содержимое
	// O_CREAT - если файла нет - создаст
	// 0777 - разрешения для файла (нужны другие)
	dup2(out, 1);// теперь при вызове 1 мы будем обращаться к out
	return (0);
}
