/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:36:06 by dpaper            #+#    #+#             */
/*   Updated: 2021/12/03 14:14:55 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_argc(const char *str, va_list argc)
{
	if (*str == 'c')
		return (ft_out_c(argc));
	else if (*str == 's')
		return (ft_out_s(argc));
	else if (*str == 'p')
		return (ft_out_p(argc));
	else if (*str == 'd')
		return (ft_out_id(argc));
	else if (*str == 'i')
		return (ft_out_id(argc));
	else if (*str == 'u')
		return (ft_out_u(argc));
	else if (*str == 'x')
		return (ft_out_x(argc, 'x'));
	else if (*str == 'X')
		return (ft_out_x(argc, 'X'));
	else if (*str == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	else
		return (ft_out_one(str));
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	argc;

	len = 0;
	va_start(argc, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			len += type_argc(str, argc);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			len++;
		}
		str++;
	}
	va_end(argc);
	return (len);
}
