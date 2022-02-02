/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:40:29 by dpaper            #+#    #+#             */
/*   Updated: 2021/10/17 17:50:23 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
