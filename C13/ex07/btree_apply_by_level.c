/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 16:18:40 by rlebaill          #+#    #+#             */
/*   Updated: 2026/07/24 16:48:11 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_tree.h"

void	btree_apply_by_level_rec(t_btree *root, int current_level,
						int is_first_elem, void (*applyf)(void *item,
							int current_level, int is_first_elem))
{
	if (!root)
		return ;
	applyf(root->item, current_level, is_first_elem);
	btree_apply_by_level_rec(root->left, current_level + 1,
		1 && is_first_elem, applyf);
	btree_apply_by_level_rec(root->right, current_level + 1, 0, applyf);
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
						int current_level, int is_first_elem))
{
	btree_apply_by_level_rec(root, 0, 1, applyf);
}
