/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:50:07 by ybouaoud          #+#    #+#             */
/*   Updated: 2024/05/15 17:36:45 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	pipex(t_pipe *op)
{
	if (pipe(op->fd) == -1)
		exit_status("pipe", -1);
	op->process_id1 = fork();
	op->process_id2 = fork();
	if (op->process_id1 < 0 || op->process_id2 < 0)
	{
		close(op->fd[0]);
		close(op->fd[1]);
		exit_status("fork", -1);
	}
	child_process1(op);
	waitpid(op->process_id1, NULL, 0);
	child_process2(op);
	close(op->fd[0]);
	close(op->fd[1]);
}

int	main(int argc, char *argv[], char **envp)
{
	t_pipe	*op;

	if (argc != 5)
		ft_error();
	op = parse(argv, envp);
	pipex(op);
	ft_free_all(op);
	return (0);
}
