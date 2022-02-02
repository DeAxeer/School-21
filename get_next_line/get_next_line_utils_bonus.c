/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.21-school.rudp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:16:57 by dpaper            #+#    #+#             */
/*   Updated: 2021/11/30 15:35:23 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*k;

	i = 0;
	j = 0;
	while (*(s1 + i))
		i++;
	k = (char *)malloc(sizeof(char) * i + 1);
	if ((char *)0 == k)
		return ((char *)0);
	while (j < i)
	{
		*(k + j) = *(s1 + j);
		j++;
	}
	*(k + j) = '\0';
	return (k);
}

size_t	ft_strlen(const char	*s)
{
	size_t	k;

	k = 0;
	if (!s)
		return (0);
	while (*(s + k))
		k++;
	return (k);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*k;

	if (s1 == (char *)0 && s2 == (char *)0)
		return ((char *)0);
	i = (int)ft_strlen(s1);
	j = (int)ft_strlen(s2);
	k = (char *)malloc(sizeof(char) * (i + j) + 1);
	if ((char *)0 == k)
		return ((char *)0);
	i = 0;
	while (*(s1 + i))
		*k++ = *(char *)(s1 + i++);
	j = 0;
	while (*(s2 + j))
		*k++ = *(char *)(s2 + j++);
	*k = '\0';
	free ((char *)(s1));
	return (k - i - j);
}

char	*ft_strchr(const char *s, int c)
{
	char	*k;

	if (!s)
		return (0);
	k = (char *)s;
	while (*k)
	{
		if (*k == (char)c)
			return (k);
		k++;
	}
	if (*k == (char)c)
		return (k);
	return ((char *)0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*k;
	size_t	i;

	if (s == (char *)0)
		return ((char *)0);
	i = ft_strlen(s);
	if (start >= (unsigned int)i)
	{
		k = (char *)malloc(sizeof(char));
		if ((char *)0 == k)
			return ((char *)0);
		*k = '\0';
		return (k);
	}
	if (i <= len)
		k = (char *)malloc(sizeof(char) * i + 1);
	else
		k = (char *)malloc(sizeof(char) * len + 1);
	if ((char *)0 == k)
		return ((char *)0);
	i = -1;
	while (++i < len && *(s + start + (unsigned int)i))
		*(k + i) = *(char *)(s + start + (unsigned int)i);
	*(k + i) = '\0';
	return (k);
}
