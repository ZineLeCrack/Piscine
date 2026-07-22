/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 09:08:50 by romain            #+#    #+#             */
/*   Updated: 2026/07/22 09:14:28 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_swap(t_list **a, t_list **b)
{
	void	*tmp;

	tmp = (*a)->data;
	(*a)->data = (*b)->data;
	(*b)->data = tmp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*i;
	t_list	*j;

	if (!*begin_list)
		return ;
	i = (*begin_list);
	while (i->next)
	{
		j = i->next;
		while (j)
		{
			if (cmp(i->data, j->data) > 0)
				ft_swap(&i, &j);
			j = j->next;
		}
		i = i->next;
	}
}
