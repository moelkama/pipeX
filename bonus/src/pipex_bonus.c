/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <moelkama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:10:53 by moelkama          #+#    #+#             */
/*   Updated: 2023/03/16 12:15:03 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

int	ft_cmpstr(char *s1, char *s2)
{
	while (*s1 && *(s1++) == *(s2++))
		;
	return (*s1 - *s2);
}

void	exchere_doc(char ***commands, int c, char **v, int **fd)
{
	char	*line;
	char	*exit;

	if (!fd)
		return ;
	fd[0] = (int *)malloc(2 * sizeof(int ));
	fd[1] = (int *)malloc(2 * sizeof(int ));
	if (!fd[0] || !fd[1])
		return ;
	pipe(fd[0]);
	pipe(fd[0]);
	ft_putstr_fd("pipe heredoc> ", 1, 0);
	line = get_next_line(0);
	exit = ft_link(v[2], "\n");
	while (line && ft_cmpstr(line, exit) != 0)
	{
		ft_putstr_fd("pipe heredoc> ", 1, 0);
		ft_putstr_fd(line, fd[0][1], 0);
		free(line);
		free(exit);
		exit = ft_link(v[2], "\n");
		line = get_next_line(0);
	}
}

void	multiplepipe(char ***commands, char **env, int *file)
{
	int	index;
	int	fd[2];

	if (file[1] == -1)
		ft_putstr_fd("file output is a directory!", 2, 1);
	else
	{
		dup2(file[0], 0);
		index = 0;
		while (commands[index])
		{
			exccommands(commands, env, file, index);
			index++;
		}
	}
}

int	main(int c, char **v, char **env)
{
	char	***commands;
	int		file[2];
	int		**fd;

	if (c == 6 && ft_cmpstr(v[1], "here_doc") == 0)
	{
		fd = (int **)malloc((c - 4) * sizeof(int *));
		file[1] = open(v[c - 1], O_RDWR | O_APPEND | O_CREAT, 0644);
		commands = findcommands(c - 2, v + 2);
		exchere_doc(commands, c, v, fd);
		here_docfirst(commands, env, fd);
		here_doclast(commands, env, file[1], fd);
	}
	else if (c >= 5)
	{
		file[0] = open(v[1], O_RDONLY);
		file[1] = open(v[c - 1], O_RDWR | O_TRUNC | O_CREAT, 0644);
		commands = findcommands(c - 1, v + 1);
		multiplepipe(commands, env, file);
	}
	else
		ft_putstr_fd("argements leas than 5 or \"here_doc\" keyword!", 2, 1);
	while (wait(NULL) != -1)
		;
}
