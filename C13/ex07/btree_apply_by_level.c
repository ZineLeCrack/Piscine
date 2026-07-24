/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 16:18:40 by rlebaill          #+#    #+#             */
/*   Updated: 2026/07/24 17:34:13 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_tree.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	btree_level_count(t_btree *root)
{
	if (!root)
		return (0);
	return (1 + max(btree_level_count(root->left),
			btree_level_count(root->right)));
}

int	btree_apply_by_level_rec(t_btree *root, t_level level,
							void (*applyf)(void *item, int current_level,
								int is_first_elem))
{
	int	n;

	if (!root)
		return (0);
	if (level.current_level == level.level)
	{
		applyf(root->item, level.current_level, level.is_first_elem);
		return (1);
	}
	else
	{
		level.current_level += 1;
		n = btree_apply_by_level_rec(root->left, level, applyf);
		level.is_first_elem *= (!n);
		n |= btree_apply_by_level_rec(root->right, level, applyf);
		return (n);
	}
	return (0);
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
						int current_level, int is_first_elem))
{
	t_level	level;
	int		levels;
	int		i;

	levels = btree_level_count(root);
	i = 0;
	while (i < levels)
	{
		level.level = i;
		level.current_level = 0;
		level.is_first_elem = 1;
		btree_apply_by_level_rec(root, level, applyf);
		i++;
	}
}
