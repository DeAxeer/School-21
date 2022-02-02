/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 17:56:11 by dpaper            #+#    #+#             */
/*   Updated: 2021/10/19 21:21:38 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_kolnum(int n, unsigned int l, int i)
{
	if (n < 0)
	{
		l = -n;
		i++;
	}
	while (l / 10)
	{
		i++;
		l /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int					i;
	unsigned int		l;
	char				*k;

	i = 1;
	l = n;
	i = ft_kolnum(n, l, i);
	l = n;
	k = (char *)malloc(sizeof(char) * (i + 1));
	if (k == (char *)0)
		return ((char *)0);
	if (n < 0)
	{
		k[0] = '-';
		l = -n;
	}
	k[i] = '\0';
	while (l / 10)
	{
		k[i - 1] = (l % 10) + '0';
		l /= 10;
		i--;
	}
	k[i - 1] = l + '0';
	return (k);
}
