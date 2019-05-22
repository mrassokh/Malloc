/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listpushback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 17:24:18 by mrassokh          #+#    #+#             */
/*   Updated: 2017/01/19 15:00:40 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (!alst || !new)
		return ;
	if (!(*alst))
	{
		(*alst) = new;
		return ;
	}
	tmp = (*alst);
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
}
