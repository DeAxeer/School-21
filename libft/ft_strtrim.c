/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:05:08 by dpaper            #+#    #+#             */
/*   Updated: 2021/10/19 21:23:51 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char const *s1, char const *set)
{
	int	i;
	int	k;
	int	n;

	i = 0;
	k = 0;
	n = 0;
	while (*(s1 + i))
	{
		while (*(set + k))
		{
			if (*(s1 + i) == *(set + k))
				n = 1;
			k++;
		}
		if (!n)
			break ;
		k = 0;
		n = 0;
		i++;
	}
	if (i == (int)ft_strlen(s1))
		return (-1);
	return (i);
}

static int	ft_end(char const *s1, char const *set)
{
	int	j;
	int	k;
	int	n;

	n = 0;
	k = 0;
	j = (int)ft_strlen(s1) - 1;
	while (*(s1 + j))
	{
		while (*(set + k))
		{
			if (*(s1 + j) == *(set + k))
				n = 1;
			k++;
		}
		if (!n)
			break ;
		k = 0;
		n = 0;
		j--;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*k;
	int		o;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = ft_start(s1, set);
	if (i == -1)
	{
		k = (char *)malloc(sizeof(char));
		*k = '\0';
		return (k);
	}
	j = ft_end(s1, set);
	k = (char *)malloc(sizeof(char) * (j - i) + 2);
	if (k == NULL)
		return (NULL);
	o = 0;
	while (i < j + 1 && *(s1 + i))
		*(k + o++) = *(char *)(s1 + i++);
	*(k + o) = '\0';
	return (k);
}
