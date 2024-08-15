/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:28:44 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/09/20 12:24:55 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

void	ft_free(char **mat);
void	ft_exit(char *msg, int ex);
void	ft_clean(char **cmd, int fd, char *str);
char	*get_path(char *p, char *cmd);
char	*create_path(char *cmd, char **envp);
void	dup_fd(int flag, int *fd, int f);
void	child(char **envp, char **argv, int fd[2], int i);

#endif