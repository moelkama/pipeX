/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utilse_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <moelkama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:13:19 by moelkama          #+#    #+#             */
/*   Updated: 2023/03/16 11:42:36 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_docfirst(char ***commands, char **env, int **fd)
{
	char	*path;
	int		pid;

	pipe(fd[1]);
	dup2(fd[0][0], 0);
	dup2(fd[1][1], 1);
	close(fd[0][1]);
	pid = fork();
	if (pid == 0)
	{
		path = findpath(commands[0][0], env);
		if (path)
			execve(path, commands[0], env);
		else
		{
			ft_putstr_fd("Command not found : ", 2, 0);
			ft_putstr_fd(commands[0][0], 2, 1);
		}
		exit(1);
	}
}

void	here_doclast(char ***commands, char **env, int file2, int **fd)
{
	char	*path;
	int		pid;

	dup2(file2, 1);
	close(fd[1][1]);
	dup2(fd[1][0], 0);
	close(fd[1][0]);
	pid = fork();
	if (pid == 0)
	{
		path = findpath(commands[1][0], env);
		if (path)
			execve(path, commands[1], env);
		else
		{
			ft_putstr_fd("Command not found : ", 2, 0);
			ft_putstr_fd(commands[1][0], 2, 1);
		}
		exit(1);
	}
}

void	exccommands(char ***commands, char **env, int *file, int k)
{
	char	*path;
	int		fd[2];
	int		pid;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		if (!commands[k + 1])
			dup2(file[1], 1);
		else
			dup2(fd[1], 1);
		close(fd[1]);
		close(fd[0]);
		path = findpath(commands[k][0], env);
		if (path && commands[k][0][0] != '.')
			execve(path, commands[k], env);
		ft_putstr_fd("Command not found : ", 2, 0);
		ft_putstr_fd(commands[k][0], 2, 1);
		exit(1);
	}
	dup2(fd[0], 0);
	close(fd[0]);
	close(fd[1]);
}
