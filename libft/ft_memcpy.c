/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:28:54 by dpaper            #+#    #+#             */
/*   Updated: 2021/10/17 17:46:47 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t	i;
	char	*destin;
	char	*sourc;

	i = 0;
	if (!src && !dst)
		return ((void *)0);
	destin = (char *)dst;
	sourc = (char *)src;
	while (i < n)
	{
		*(destin + i) = *(sourc + i);
		i++;
	}
	return (dst);
}
