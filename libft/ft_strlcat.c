/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:02:12 by dpaper            #+#    #+#             */
/*   Updated: 2021/10/14 15:24:12 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	k;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(src);
	k = ft_strlen(dst);
	if (k >= dstsize)
		return (j + dstsize);
	while ((i + k + 1) < dstsize && *(src + i))
	{
		*(dst + k + i) = *(src + i);
		i++;
	}
	*(dst + k + i) = '\0';
	return (k + j);
}
