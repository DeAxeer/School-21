/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:22:52 by dpaper            #+#    #+#             */
/*   Updated: 2021/10/13 12:46:50 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (*(src + i))
	{
		if (i < dstsize)
			*(dst + i) = *(src + i);
		if (i == dstsize - 1)
			*(dst + i) = '\0';
		i++;
	}
	if (dstsize > i)
		*(dst + i) = '\0';
	return (i);
}
