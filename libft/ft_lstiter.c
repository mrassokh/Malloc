/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 07:36:56 by mrassokh          #+#    #+#             */
/*   Updated: 2016/11/29 07:45:52 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*cursor;

	if (lst && f)
	{
		cursor = lst;
		while (cursor)
		{
			(*f)(cursor);
			cursor = cursor->next;
		}
	}
}
