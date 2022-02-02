/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 21:16:17 by dpaper            #+#    #+#             */
/*   Updated: 2021/10/19 19:26:45 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*huk;
	t_list	*lol;

	if (!lst || !del)
		return ;
	huk = *lst;
	while (huk -> next != NULL)
	{
		del(huk -> content);
		lol = huk -> next;
		free(huk);
		huk = lol;
	}
	del(huk -> content);
	free(huk);
	*lst = NULL;
}
