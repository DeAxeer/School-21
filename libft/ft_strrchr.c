/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:07:17 by dpaper            #+#    #+#             */
/*   Updated: 2021/10/17 17:49:53 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*k;
	int		i;

	i = 0;
	k = (char *)s;
	while (*k)
	{
		k++;
		i++;
	}
	if (*k == (char)c)
		return (k);
	while (i != -1)
	{
		if (*k == (char)c)
			return (k);
		k--;
		i--;
	}
	return ((char *)0);
}
