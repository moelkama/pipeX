/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <moelkama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:58:11 by moelkama          #+#    #+#             */
/*   Updated: 2023/03/15 18:56:51 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	***findcommands(int size, char **arr);
char	**ft_split(char *str, char c);
char	*ft_link(char *s1, char *s2);
char	*findpath(char *command, char **env);
int		ft_strlen(char *str);
int		ft_free(char **strs);
void	ft_putstr_fd(char *str, int fd, int end);

#endif
