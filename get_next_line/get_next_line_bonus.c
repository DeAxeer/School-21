/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.21-school.rudp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:17:00 by dpaper            #+#    #+#             */
/*   Updated: 2021/11/30 15:35:51 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*new_line(char **know, int i)
{
	char	*temp;
	char	*tono;

	tono = ft_substr(*know, 0, i + 1);
	temp = ft_strdup(&((*know)[i + 1]));
	free (*know);
	*know = temp;
	if ((*know)[0] == '\0')
	{
		free (*know);
		*know = NULL;
	}
	return (tono);
}

static char	*to_by_str(char **know)
{
	int		i;
	char	*tono;

	if (*know == NULL)
		return (NULL);
	i = (int)(ft_strchr(*know, '\n') - *know);
	if (ft_strchr(*know, '\n'))
		tono = new_line(know, i);
	else
	{
		tono = ft_strdup(*know);
		free (*know);
		*know = NULL;
	}
	return (tono);
}

char	*get_next_line(int fd)
{
	char		*k;
	int			la;
	static char	*know[FD_AMOUNT];

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	k = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (k == NULL)
		return (NULL);
	la = 1;
	while (!ft_strchr(know[fd], '\n') && la)
	{
		la = read(fd, k, BUFFER_SIZE);
		if (la <= 0)
			break ;
		k[la] = '\0';
		if (know[fd] == NULL)
			know[fd] = ft_strdup(k);
		else
			know[fd] = ft_strjoin(know[fd], k);
	}
	free (k);
	return (to_by_str(&know[fd]));
}
