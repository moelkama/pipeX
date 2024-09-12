/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <moelkama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:10:53 by moelkama          #+#    #+#             */
/*   Updated: 2023/03/16 11:00:12 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putstr_fd(char *str, int fd, int end)
{
	if (str)
	{
		while (*str)
			write(fd, str++, 1);
	}
	if (end == 1)
		write(fd, "\n", 1);
}

char	*ft_link(char *s1, char *s2)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(len * sizeof(char ) + sizeof(char ));
	if (str)
	{
		i = 0;
		j = 0;
		while (s1 && s1[j])
			str[i++] = s1[j++];
		j = 0;
		while (s2 && i < len)
			str[i++] = s2[j++];
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}

void	ft_close(int *file)
{
	close(file[3]);
	close(file[2]);
}

void	execcmd(char ***commands, char **env, int *file, int k)
{
	char	*path;
	int		pid;

	pid = fork();
	if (pid == 0)
	{
		if (k == 0 && file[0] == -1)
			ft_putstr_fd("file input not found!", 2, 1);
		else
		{
			path = findpath(commands[k][0], env);
			if (k == 0)
				dup2(file[3], 1);
			else
				dup2(file[2], 0);
			dup2(file[k], k);
			ft_close(file);
			if (path && commands[k][0][0] != '.')
				execve(path, commands[k], env);
			ft_putstr_fd("Command not found : ", 2, 0);
			ft_putstr_fd(commands[k][0], 2, 1);
		}
		exit(1);
	}
}

int	main(int c, char **v, char **env)
{
	char	***commands;
	int		file[4];

	commands = findcommands(c - 1, v + 1);
	file[0] = open(v[1], O_RDONLY);
	if (c == 5 && commands)
	{
		file[1] = open(v[4], O_RDWR | O_TRUNC | O_CREAT, 0644);
		if (file[1] == -1)
		{
			ft_putstr_fd(v[4], 2, 0);
			ft_putstr_fd(" : is a directory!", 2, 1);
		}
		else
		{
			pipe(&file[2]);
			execcmd(commands, env, file, 0);
			execcmd(commands, env, file, 1);
			ft_close(file);
		}
	}
	else
		ft_putstr_fd("check the number of arguments!", 2, 1);
	while (wait(NULL) != -1)
		;
}
