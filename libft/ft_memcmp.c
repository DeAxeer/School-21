/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:11:43 by dpaper            #+#    #+#             */
/*   Updated: 2021/10/10 17:36:05 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	k;

	k = 0;
	while (n > k)
	{
		if ((*(unsigned char *)(s1 + k) - *(unsigned char *)(s2 + k)) != 0)
			return (*(unsigned char *)(s1 + k) - *(unsigned char *)(s2 + k));
		k++;
	}
	return (0);
}
