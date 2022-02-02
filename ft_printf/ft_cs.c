/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:37:01 by dpaper            #+#    #+#             */
/*   Updated: 2021/12/03 14:14:53 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_out_c(va_list argc)
{
	ft_putchar_fd((va_arg(argc, int)), 1);
	return (1);
}

int	ft_out_s(va_list argc)
{
	char	*str;

	str = va_arg(argc, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_out_one(const char *str)
{
	ft_putchar_fd(*str, 1);
	return (1);
}
