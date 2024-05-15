/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:43:42 by ybouaoud          #+#    #+#             */
/*   Updated: 2024/05/15 19:45:18 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_process1(t_pipe *op)
{
	if (op->process_id1 == 0)
	{
		op->stdin_fd = open(op->file1, O_RDONLY);
		if (op->stdin_fd == -1)
			exit_status("open", -1);
		if ((dup2(op->stdin_fd, STDIN_FILENO)) == -1
			|| (dup2(op->fd[1], STDOUT_FILENO)) == -1)
		{
			close(op->stdin_fd);
			exit_status("dup2", -1);
		}
		close(op->fd[0]);
		close(op->fd[1]);
		if (execve(op->path, op->cmd1, op->envr) == -1)
		{
			exit_status("execve", -1);
			ft_free_all(op);
			exit(1);
		}
	}
}

void	child_process2(t_pipe *op)
{
	if (op->process_id2 == 0)
	{
		op->stdout_fd = open(op->file2, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (op->stdout_fd == -1)
			exit_status("open", -1);
		if ((dup2(op->fd[0], STDIN_FILENO)) == -1
			|| (dup2(op->stdout_fd, STDOUT_FILENO)) == -1)
		{
			close(op->stdout_fd);
			exit_status("dup2", -1);
		}
		close(op->fd[0]);
		close(op->fd[1]);
		if (execve(op->path2, op->cmd2, op->envr) == -1)
		{
			exit_status("execve", -1);
			ft_free_all(op);
			exit(1);
		}
	}
}
