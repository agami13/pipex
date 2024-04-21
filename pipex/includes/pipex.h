/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 22:49:17 by ybouaoud          #+#    #+#             */
/*   Updated: 2024/04/21 22:49:18 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

void			ft_error(void);
void			pipex(char **argv, char **envp);
void			child_process(char **argv, int *fd, char **envp);
void			parent_process(char **argv, int *fd, char **envp);
void			execute_cmd(char *argv, char **envp);
char			*get_path(char **envp, char *cmd);
void			ft_free(char **str);

#endif