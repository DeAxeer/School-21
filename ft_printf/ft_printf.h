/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:26:45 by dpaper            #+#    #+#             */
/*   Updated: 2022/01/07 17:49:12 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);

int		ft_out_c(va_list argc);
int		ft_out_s(va_list argc);
int		ft_out_p(va_list argc);
int		ft_out_one(const char *str);
int		ft_out_id(va_list argc);
int		ft_out_u(va_list argc);
int		ft_out_x(va_list argc, char x);

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char	*s);

#endif