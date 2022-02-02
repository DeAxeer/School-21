/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:48:03 by dpaper            #+#    #+#             */
/*   Updated: 2021/10/17 17:48:35 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*k;

	i = 0;
	j = 0;
	while (*(s1 + i))
		i++;
	k = (char *)malloc(sizeof(char) * i + 1);
	if ((char *)0 == k)
		return ((char *)0);
	while (j < i)
	{
		*(k + j) = *(s1 + j);
		j++;
	}
	*(k + j) = '\0';
	return (k);
}
