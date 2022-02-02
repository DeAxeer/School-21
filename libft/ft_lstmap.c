/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaper <dpaper@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 21:20:25 by dpaper            #+#    #+#             */
/*   Updated: 2021/10/19 21:02:52 by dpaper           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*k;
	t_list	*eol;

	if (!lst || !f)
		return (NULL);
	eol = NULL;
	while (lst)
	{
		k = ft_lstnew(f(lst -> content));
		ft_lstadd_back(&eol, k);
		if (!k)
		{
			ft_lstclear(&eol, del);
			return (NULL);
		}
		lst = lst -> next;
	}
	return (eol);
}
