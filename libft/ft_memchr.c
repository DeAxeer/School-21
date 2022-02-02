/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:34:50 by dpaper            #+#    #+#             */
/*   Updated: 2021/10/13 13:55:04 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*k;
	size_t			i;

	i = 0;
	if (n == 0)
		return (NULL);
	k = (unsigned char *)s;
	while (i < n)
	{
		if (*(k + i) == (unsigned char)c)
			return ((void *)(k + i));
		i++;
	}
	return (NULL);
}
