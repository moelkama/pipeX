/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <moelkama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:58:11 by moelkama          #+#    #+#             */
/*   Updated: 2023/03/15 19:21:34 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 1

# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*get_next_line2(char **ptr, int fd, char **str, char **swp);
char	*ft_free2(char *s1, char *s2);
int		ft_strlenf(char *str, char c);
int		ft_check(char *str);
char	*ft_link(char *s1, char *s2);
int		ft_strlenf(char *str, char c);
void	ft_bezero(char *str);
char	***findcommands(int size, char **arr);
char	**ft_split(char *str, char c);
char	*ft_link(char *s1, char *s2);
char	*findpath(char *command, char **env);
int		ft_free(char **strs);
void	ft_putstr_fd(char *str, int fd, int end);
void	exccommands(char ***commands, char **env, int *file, int k);
void	here_docfirst(char ***commands, char **env, int **fd);
void	here_doclast(char ***commands, char **env, int file2, int **fd);

#endif
