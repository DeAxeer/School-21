/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:09:35 by dpaper            #+#    #+#             */
/*   Updated: 2022/02/14 15:44:35 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "stdio.h"

char	**ft_path(char **env)
{
	int		i;
	char	*pathis;
	char	**path;

	i = 0;
	pathis = NULL;
	while (pathis == NULL)
		pathis = ft_strnstr(env[i++], "PATH", 4);
	path = ft_split(pathis + 5, ':');
	return (path);
}

void	ft_free(char **path)
{
	int	i;

	i = 0;
	while (path[i])
		free(path[i++]);
	free(path);
}

char	*ft_cmd(char *argv, char **env)
{
	int		i;
	char	*cmd;
	char	*tmp;
	char	**path;

	i = 0;
	path = ft_path(env);
	while (path[i])
	{
		tmp = ft_strjoin("/", argv);
		cmd = ft_strjoin(path[i], tmp);
		free(tmp);
		if (!access(cmd, 0))
		{
			ft_free(path);
			return (cmd);
		}
		free(cmd);
		i++;
	}
	i = 0;
	ft_free(path);
	return (NULL);
}
