/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:11:44 by dpaper            #+#    #+#             */
/*   Updated: 2021/10/14 13:08:22 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void	*b, int c, size_t len)
{
	size_t	i;
	char	*k;

	i = 0;
	k = (char *)b;
	while (i < len)
	{
		*(k + i) = c;
		i++;
	}
	return ((void *)k);
}