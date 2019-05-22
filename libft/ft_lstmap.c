/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 07:48:02 by mrassokh          #+#    #+#             */
/*   Updated: 2016/11/29 12:38:01 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*cursor;
	t_list	*ret;

	if (!lst || !f)
		return (NULL);
	new_lst = (*f)(lst);
	if (!new_lst)
		return (NULL);
	ret = new_lst;
	cursor = lst->next;
	while (cursor)
	{
		new_lst->next = (*f)(cursor);
		new_lst = new_lst->next;
		if (!new_lst)
			return (NULL);
		cursor = cursor->next;
	}
	return (ret);
}
