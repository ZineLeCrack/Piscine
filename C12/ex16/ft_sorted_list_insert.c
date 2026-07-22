/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 09:21:42 by romain            #+#    #+#             */
/*   Updated: 2026/07/22 09:44:37 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data);

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*i;
	t_list	*new;

	new = ft_create_elem(data);
	if (!*begin_list)
	{
		(*begin_list) = new;
		return ;
	}
	i = (*begin_list);
	while (i->next && cmp(data, i->next->data) > 0)
		i = i->next;
	if (!i->next)
		i->next = new;
	else
	{
		new->next = i->next;
		i->next = new;
	}
}
