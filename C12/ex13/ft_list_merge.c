/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 08:56:04 by romain            #+#    #+#             */
/*   Updated: 2026/07/22 09:08:17 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*i;

	i = (*begin_list1);
	if (!i)
	{
		(*begin_list1) = begin_list2;
		return ;
	}
	while (i->next)
		i = i->next;
	i->next = begin_list2;
}
