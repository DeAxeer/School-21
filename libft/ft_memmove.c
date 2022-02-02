/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:38:34 by dpaper            #+#    #+#             */
/*   Updated: 2021/10/17 17:47:28 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	*destin;
	char	*sourc;

	i = 0;
	if (!dst && !src)
		return ((void *)0);
	destin = (char *)dst;
	sourc = (char *)src;
	if (dst > src)
	{
		i = (int)len;
		while (i--)
			*(destin + i) = *(sourc + i);
	}
	else
	{
		while (i < (int)len)
		{
			*(destin + i) = *(sourc + i);
			i++;
		}
	}
	return (dst);
}
