/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:19:21 by dpaper            #+#    #+#             */
/*   Updated: 2021/10/17 17:47:55 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*k;

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
