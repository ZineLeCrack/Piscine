/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 08:42:57 by romain            #+#    #+#             */
/*   Updated: 2026/07/22 08:55:36 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove(t_list **begin_list, t_list **prev,
				t_list **next, void (*free_fct)(void *))
{
	free_fct((*next)->data);
	if (*prev)
	{
		(*next) = (*next)->next;
		free((*prev)->next);
		(*prev)->next = (*next);
	}
	else
	{
		(*prev) = (*next);
		(*next) = (*next)->next;
		(*begin_list) = (*next);
		free(*prev);
		(*prev) = NULL;
	}
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
					int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*i;
	t_list	*j;

	i = NULL;
	j = *begin_list;
	while (j)
	{
		if (cmp(j->data, data_ref) == 0)
			ft_list_remove(begin_list, &i, &j, free_fct);
		else
		{
			i = j;
			j = j->next;
		}
	}
}
