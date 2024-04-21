/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 22:50:31 by ybouaoud          #+#    #+#             */
/*   Updated: 2024/04/21 22:57:34 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_process(char **argv, int *fd, char **envp)
{
	int	stdin;

	stdin = open(argv[1], O_RDONLY, 0777);
	if (stdin == -1)
		return (ft_error());
	if ((dup2(fd[1], STDOUT_FILENO) == -1)
		|| (dup2(stdin, STDIN_FILENO) == -1))
		return (perror("dup2"));
	close(fd[0]);
	execute_cmd(argv[2], envp);
}

void	parent_process(char **argv, int *fd, char **envp)
{
	int	stdout;

	stdout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (stdout == -1)
		return (ft_error());
	if ((dup2(fd[0], STDIN_FILENO) == -1)
		|| (dup2(stdout, STDOUT_FILENO) == -1))
		return (perror("dup2"));
	close(fd[1]);
	execute_cmd(argv[3], envp);
}

void	pipex(char **argv, char **envp)
{
	int		fd[2];
	pid_t	process_id;

	if (pipe(fd) == -1)
		return (perror("pipe"));
	process_id = fork();
	if (process_id < 0)
		return (perror("fork"));
	if (process_id == 0)
		child_process(argv, fd, envp);
	waitpid(process_id, NULL, 0);
	parent_process(argv, fd, envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	if (argc != 5)
	{
		ft_printf("Usage: ./pipex file1 cmd1 cmd2 file2\n");
		return (1);
	}
	else
		pipex(argv, envp);
	return (0);
}
