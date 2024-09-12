/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <moelkama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:17:18 by moelkama          #+#    #+#             */
/*   Updated: 2023/03/15 19:28:03 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_strlenf(char *str, char c)
{
	int	len;

	len = 0;
	while (str && str[len])
	{
		if (str[len] == c)
			return (len + 1);
		len++;
	}
	return (len);
}

char	*get_next_line(int fd)
{
	static char	*ptr;
	char		*str;
	char		*swp1;
	char		*swp;

	str = (char *)malloc(BUFFER_SIZE * sizeof(char ) + sizeof(char ));
	if (str)
	{
		str[BUFFER_SIZE] = '\0';
		if (ptr && ft_check(ptr))
		{
			swp = ft_link(NULL, ptr);
			swp1 = ptr;
			ptr = ft_link(ptr + ft_strlenf(ptr, '\n'), NULL);
			ft_free2(str, swp1);
			if (ft_strlenf(ptr, '\0') == 0)
				ptr = ft_free2(ptr, NULL);
			return (swp);
		}
		ft_bezero(str);
		return (get_next_line2(&ptr, fd, &str, &swp));
	}
	return (NULL);
}
