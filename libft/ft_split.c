/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:35:05 by dpaper            #+#    #+#             */
/*   Updated: 2021/10/19 21:22:56 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numwor(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	return (i);
}

static void	ft_malwor(char *k, char const *s, char c)
{
	int	j;

	j = 0;
	while (*s && *s != c)
		k[j++] = *s++;
	k[j] = '\0';
}

static char	**ft_clear(char **k, int i)
{
	int	f;

	f = 0;
	while (f <= i)
	{
		free(k[f]);
		f++;
	}
	free (k);
	return (NULL);
}

static char	**ft_wwords(char **k, char const *s, char c, int p)
{
	int	i;
	int	m;

	i = 0;
	m = 0;
	while (*s && i < p)
	{
		while (*s && *s == c)
			s++;
		while (*(s + m) && *(s + m) != c)
			m++;
		k[i] = (char *)malloc(sizeof(char) * (m + 1));
		if (k[i] == NULL)
			return (ft_clear(k, i));
		ft_malwor(k[i], s, c);
		s = s + m;
		m = 0;
		i++;
	}
	k[i] = NULL;
	return (k);
}

char	**ft_split(char const *s, char c)
{
	char	**k;
	int		i;

	if (s == NULL)
		return (NULL);
	i = ft_numwor(s, c);
	k = (char **)malloc(sizeof(char *) * (i + 1));
	if (NULL == k)
		return (NULL);
	return (ft_wwords(k, s, c, i));
}
