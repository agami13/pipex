/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:46:48 by ybouaoud          #+#    #+#             */
/*   Updated: 2024/05/15 17:31:04 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef	struct	s_struct {
	char	**cmd1;
	char	**cmd2;
	char	**argv;
	char	**envr;
	char	*file1;
	char	*file2;
	char	*path;
	char	*path2;
	pid_t	process_id1;
	pid_t	process_id2;
	int		fd[2];
	int		stdin_fd;
	int		stdout_fd;
}	t_pipe;

t_pipe			*parse(char **argv, char **envr);
char			*get_path(char **envp, char *cmd);
void			ft_error(void);
void			ft_free(char **str);
void			give_value(t_pipe **op, char **envp, char **argv);
void			ft_free_all(t_pipe *op);
void			pipex(t_pipe *op);
void			exit_status(char *failed, int status);
void			child_process1(t_pipe *op);
void			child_process2(t_pipe *op);


#endif