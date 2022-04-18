/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:41:23 by ahertha           #+#    #+#             */
/*   Updated: 2022/04/09 01:07:20 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child(int fd[2], char *file1, char *cmd1, char **envp)
{
	int	filein;

	filein = open(file1, O_RDONLY, 0777);
	if (filein == -1)
		write_error("Could not open file.\n");
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	execute_command(cmd1, envp);
}

void	parent(int fd[2], char *file2, char *cmd2, char **envp)
{
	int	fileout;

	fileout = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		write_error("Could not open file.\n");
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	execute_command(cmd2, envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
	{
		ft_putstr_fd("Invalid number of arguments.\n", 1);
		ft_putstr_fd("Ex: ./pipex file1 cmd1 cmd2 file2\n", 1);
		return (0);
	}
	else
	{
		if (pipe(fd) == -1)
			write_error("Pipe error.\n");
		pid = fork();
		if (pid == -1)
			write_error("Fork error.\n");
		if (pid == 0)
			child(fd, argv[1], argv[2], envp);
		waitpid(pid, NULL, 0);
		parent(fd, argv[4], argv[3], envp);
	}
}
