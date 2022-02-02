/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:20:59 by dpaper            #+#    #+#             */
/*   Updated: 2022/01/07 15:17:18 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_kolnum_x(unsigned int l)
{
	int	i;

	i = 1;
	while (l / 16)
	{
		i++;
		l /= 16;
	}
	return (i);
}

static int	ft_nine_ten_x(unsigned int l, char x)
{
	if (l % 16 >= 0 && l % 16 <= 9)
		return ('0');
	else if (x == 'x')
		return ('W');
	else
		return ('7');
}

static void	ft_delhex(char *k, unsigned int l, int i, char x)
{
	k[i] = '\0';
	while (l / 16)
	{
		k[i - 1] = (l % 16) + ft_nine_ten_x(l, x);
		l /= 16;
		i--;
	}
	k[i - 1] = l + ft_nine_ten_x(l, x);
}

static int	ft_itoa_x(unsigned int l, char x)
{
	int			i;
	char		*k;

	i = ft_kolnum_x(l);
	k = (char *)malloc(sizeof(char) * (i + 1));
	if (k == (char *)0)
		return ((int)0);
	ft_delhex(k, l, i, x);
	ft_putstr_fd(k, 1);
	free(k);
	return (i);
}

int	ft_out_x(va_list argc, char x)
{
	unsigned int	i;

	i = va_arg(argc, unsigned int);
	return (ft_itoa_x(i, x));
}
