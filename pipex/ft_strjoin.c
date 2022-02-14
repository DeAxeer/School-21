/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:52:28 by dpaper            #+#    #+#             */
/*   Updated: 2022/02/04 17:58:16 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char	*s)
{
	size_t	k;

	k = 0;
	while (*(s + k))
		k++;
	return (k);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*k;

	if (s1 == (char *)0 || s2 == (char *)0)
		return ((char *)0);
	i = (int)ft_strlen(s1);
	j = (int)ft_strlen(s2);
	k = (char *)malloc(sizeof(char) * (i + j) + 1);
	if ((char *)0 == k)
		return ((char *)0);
	i = 0;
	while (*(s1 + i))
	{
		*(k + i) = *(char *)(s1 + i);
		i++;
	}
	j = 0;
	while (*(s2 + j))
	{
		*(k + i + j) = *(char *)(s2 + j);
		j++;
	}
	*(k + i + j) = '\0';
	return (k);
}
