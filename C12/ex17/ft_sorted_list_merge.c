/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 09:50:47 by romain            #+#    #+#             */
/*   Updated: 2026/07/22 10:02:20 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_sorted_list_insert(t_list **begin_list, t_list *node, int (*cmp)())
{
	t_list	*i;

	if (!*begin_list)
	{
		(*begin_list) = node;
		node->next = NULL;
		return ;
	}
	i = (*begin_list);
	while (i->next && cmp(node->data, i->next->data) > 0)
		i = i->next;
	if (!i->next)
	{
		i->next = node;
		node->next = NULL;
	}
	else
	{
		node->next = i->next;
		i->next = node;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1,
					t_list *begin_list2, int (*cmp)())
{
	t_list	*next;

	while (begin_list2)
	{
		next = begin_list2->next;
		ft_sorted_list_insert(begin_list1, begin_list2, cmp);
		begin_list2 = next;
	}
}
