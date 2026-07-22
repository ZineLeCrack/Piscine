/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 09:14:55 by romain            #+#    #+#             */
/*   Updated: 2026/07/22 09:20:31 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	count;

	count = 0;
	while (begin_list)
	{
		count++;
		begin_list = begin_list->next;
	}
	return (count);
}

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	while (begin_list && i < nbr)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (begin_list);
}

void	ft_swap(t_list *a, t_list *b)
{
	void	*tmp;

	tmp = a->data;
	a->data = b->data;
	b->data = tmp;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int	len;
	int	i;

	len = ft_list_size(begin_list);
	i = 0;
	while (i < len / 2)
	{
		ft_swap(ft_list_at(begin_list, i), ft_list_at(begin_list, len - i - 1));
		i++;
	}
}
