/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:05:39 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/09/20 12:36:14 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	dup_fd(int flag, int *fd, int f)
{
	if (flag)
	{
		dup2(fd[1], 1);
		dup2(f, 0);
		close(fd[0]);
	}
	else
	{
		dup2(fd[0], 0);
		dup2(f, 1);
		close(fd[1]);
	}
}

void	child(char **envp, char **argv, int fd[2], int i)
{
	char	**cmd;
	char	*path;
	int		f;

	if (i == 1)
		f = open(argv[i], O_RDONLY);
	else
		f = open(argv[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (f < 0)
		ft_exit("No such file or directory\n", 1);
	if (i == 1)
		cmd = ft_split(argv[i + 1], ' ');
	else
		cmd = ft_split(argv[i - 1], ' ');
	if (!cmd)
		ft_clean(cmd, f, "Malloc error");
	path = create_path(cmd[0], envp);
	if (!path)
		ft_clean(cmd, f, "command not found");
	dup_fd(i % 2, fd, f);
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		ft_clean(cmd, f, cmd[0]);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		return (ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile\n", 1), 0);
	if (pipe(fd) == -1)
		return (perror("pipe"), 1);
	pid1 = fork();
	if (pid1 == -1)
		return (perror("fork"), 1);
	if (pid1 == 0)
		child(envp, argv, fd, 1);
	pid2 = fork();
	if (pid2 == -1)
		return (perror("fork"), 1);
	if (pid2 == 0)
		child(envp, argv, fd, 4);
	close(fd[0]);
	close(fd[1]);
	return (0);
}
