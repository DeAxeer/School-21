/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:22:04 by dpaper            #+#    #+#             */
/*   Updated: 2021/10/17 17:49:36 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;
	size_t	t;

	t = 0;
	k = -1;
	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*(haystack + ++k))
	{
		while (*(needle + i) && *(haystack + i + k))
		{
			if (*(haystack + i + k) == *(needle + i) && (k + i) < len)
				t++;
			i++;
		}
		while (*(needle + i))
			i++;
		if (t == i)
			return ((char *)haystack + k);
		t = 0;
		i = 0;
	}
	return ((char *)0);
}
