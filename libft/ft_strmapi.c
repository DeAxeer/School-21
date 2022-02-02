/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:56:27 by dpaper            #+#    #+#             */
/*   Updated: 2021/10/19 21:23:22 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*k;
	unsigned int	i;

	if (s == (char *)0)
		return ((char *)0);
	i = ft_strlen(s);
	k = (char *)malloc(sizeof(char) * (i + 1));
	if ((char *)0 == k)
		return ((char *)0);
	i = 0;
	while (*(s + i))
	{
		k[i] = (*f)(i, *(s + i));
		i++;
	}
	k[i] = '\0';
	return (k);
}
