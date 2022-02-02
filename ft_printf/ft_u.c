/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:49:04 by dpaper            #+#    #+#             */
/*   Updated: 2021/12/03 14:14:56 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_kolnum_u(unsigned int l)
{
	int	i;

	i = 1;
	while (l / 10)
	{
		i++;
		l /= 10;
	}
	return (i);
}

static void	ft_deldec_u(char *k, unsigned int l, int i)
{
	k[i] = '\0';
	while (l / 10)
	{
		k[i - 1] = (l % 10) + '0';
		l /= 10;
		i--;
	}
	k[i - 1] = l + '0';
}

static int	ft_itoa_u(unsigned int l)
{
	int		i;
	char	*k;

	i = ft_kolnum_u(l);
	k = (char *)malloc(sizeof(char) * (i + 1));
	if (k == (char *)0)
		return ((int)0);
	ft_deldec_u(k, l, i);
	ft_putstr_fd(k, 1);
	free(k);
	return (i);
}

int	ft_out_u(va_list argc)
{
	unsigned int	i;

	i = va_arg(argc, unsigned int);
	return (ft_itoa_u(i));
}
