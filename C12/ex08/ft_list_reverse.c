/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 11:14:33 by romain            #+#    #+#             */
/*   Updated: 2026/07/21 11:47:29 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*i;
	t_list	*j;
	t_list	*k;

	if (!*begin_list || !(*begin_list)->next)
		return ;
	i = NULL;
	j = *begin_list;
	k = j->next;
	while (k)
	{
		j->next = i;
		i = j;
		j = k;
		k = k->next;
	}
	j->next = i;
	*begin_list = j;
}
