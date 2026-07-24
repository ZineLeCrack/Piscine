/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 16:04:22 by rlebaill          #+#    #+#             */
/*   Updated: 2026/07/24 16:08:37 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_tree.h"

t_btree	*btree_create_node(void *item);

void	btree_insert_data(t_btree **root, void *item,
					int (*cmpf)(void *, void *))
{
	if (!*root)
	{
		*root = btree_create_node(item);
		return ;
	}
	if (cmpf((*root)->item, item) > 0)
		btree_insert_data(&((*root)->left), item, cmpf);
	else
		btree_insert_data(&((*root)->right), item, cmpf);
}
