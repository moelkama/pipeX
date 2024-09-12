/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <moelkama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:32:57 by moelkama          #+#    #+#             */
/*   Updated: 2023/03/15 19:26:59 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_count(char *s, int start, int len)
{
	if (len > ft_strlenf(s, 0) - start && start < ft_strlenf(s, 0))
		return (ft_strlenf(s, 0) - start);
	else if (len <= ft_strlenf(s, 0) - start && start < ft_strlenf(s, 0))
		return (len);
	return (0);
}

char	*returnstr(char *s, int start, int len)
{
	char	*str;
	int		index;

	if (!s)
		return (NULL);
	str = (char *)malloc((ft_count(s, start, len) + 1) * sizeof(char ));
	if (str)
	{
		index = 0;
		while (index < len && ft_count(s, start, len) && s[start])
			str[index++] = s[start++];
		str[index] = '\0';
		return (str);
	}
	return (NULL);
}

int	ft_count_strs(char *s, char c)
{
	int	count_strs;
	int	m;

	count_strs = 0;
	while (s && *s)
	{
		while (*s && *s == c)
			s++;
		m = 0;
		while (*s && *s != c)
		{
			m = 1;
			s++;
		}
		if (m == 1)
			count_strs++;
	}
	return (count_strs);
}

int	ft_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	return (0);
}

char	**ft_split(char *str, char c)
{
	char	**strs;
	char	*ptr;
	int		count_strs;
	int		index;

	if (!str)
		return (NULL);
	count_strs = ft_count_strs(str, c);
	strs = (char **)malloc((count_strs + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	strs[count_strs] = NULL;
	index = 0;
	while (index < count_strs)
	{
		while (*str && *str == c)
			str++;
		ptr = str;
		while (*str && *str != c)
			str++;
		strs[index++] = returnstr(ptr, 0, str - ptr);
		if (!strs[index - 1])
			return (ft_free(strs), NULL);
	}
	return (strs);
}
