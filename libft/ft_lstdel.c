/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:21:45 by mrassokh          #+#    #+#             */
/*   Updated: 2016/11/29 08:47:06 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	if (!alst || !del)
		return ;
	while (*alst)
	{
		temp = (*alst)->next;
		(*del)((*alst)->content, (*alst)->content_size);
		ft_memdel((void**)alst);
		*alst = temp;
	}
	ft_memdel((void **)alst);
}
