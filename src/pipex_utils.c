/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:17:33 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/09/18 17:11:10 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_free(char **mat)
{
	int	i;

	if (!mat)
		return ;
	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	if (mat != NULL)
		free(mat);
}

void	ft_exit(char *msg, int ex)
{
	ft_putstr_fd(msg, 1);
	exit(ex);
}

void	ft_clean(char **cmd, int fd, char *str)
{
	perror(str);
	ft_free(cmd);
	if (fd > 2)
		close(fd);
	exit(1);
}

char	*get_path(char *p, char *cmd)
{
	int		i;
	char	*tmp;
	char	*path;
	char	**path_list;

	path_list = ft_split(p, ':');
	free(p);
	if (!path_list)
		ft_exit("Malloc error\n", 1);
	i = -1;
	while (path_list[++i])
	{
		tmp = ft_strjoin(path_list[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK | X_OK) == 0)
			return (ft_free(path_list), path);
		else
			free(path);
	}
	return (ft_free(path_list), NULL);
}

char	*create_path(char *cmd, char **envp)
{
	char	*path;
	int		i;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_strdup(envp[i] + 5);
			if (!path)
				ft_exit("Malloc error\n", 1);
			path = get_path(path, cmd);
			if (!path)
				return (NULL);
			else
				return (path);
		}
	}
	return (NULL);
}
