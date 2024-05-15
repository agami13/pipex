/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:50:05 by ybouaoud          #+#    #+#             */
/*   Updated: 2024/05/15 19:58:27 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exit_status(char *failed, int status)
{
	ft_printf("pipex: %s: %s\n", failed, strerror(status));
	exit(1);
}

t_pipe	*parse(char **argv, char **envp)
{
	t_pipe	*op;

	op = NULL;
	give_value(&op, argv, envp);
	if (op->path == NULL)
	{
		ft_printf("pipex: %s: command not found\n", op->cmd1[0]);
		ft_free_all(op);
		exit(127);
	}
	else if (op->path2 == NULL)
	{
		ft_printf("pipex: %s: command not found\n", op->cmd2[0]);
		ft_free_all(op);
		exit(0);
	}
	return (op);
}
