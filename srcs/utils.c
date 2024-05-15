/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:50:09 by ybouaoud          #+#    #+#             */
/*   Updated: 2024/05/15 19:58:13 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_error(void)
{
	write(2, "Error!\n", ft_strlen("Error!\n"));
	ft_printf("usage : ./pipex file1 cmd1 cmd2 file2\n");
	exit(1);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	give_value(t_pipe **op, char **argv, char **envp)
{
	(*op) = malloc(sizeof(t_pipe));
	if (!op)
		exit(1);
	(*op)->file1 = argv[1];
	(*op)->file2 = argv[4];
	(*op)->envr = envp;
	(*op)->argv = argv;
	(*op)->cmd1 = ft_split(argv[2], ' ');
	(*op)->cmd2 = ft_split(argv[3], ' ');
	(*op)->path = get_path(envp, (*op)->cmd1[0]);
	(*op)->path2 = get_path(envp, (*op)->cmd2[0]);
}

char	*get_path(char **envp, char *cmd)
{
	int		i;
	char	**paths;
	char	*path;
	char	*join;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == NULL)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		join = ft_strjoin(paths[i], "/");
		path = ft_strjoin(join, cmd);
		free(join);
		if (access(path, F_OK || X_OK) == 0)
		{
			ft_free(paths);
			return (path);
		}
		free(path);
		i++;
	}
	ft_free(paths);
	return (NULL);
}

void	ft_free_all(t_pipe *op)
{
	ft_free(op->cmd1);
	ft_free(op->cmd2);
	free(op->path);
	free(op->path2);
	free(op);
}
