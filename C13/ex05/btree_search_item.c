/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 16:09:21 by rlebaill          #+#    #+#             */
/*   Updated: 2026/07/24 16:15:09 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_tree.h"
#include <stdlib.h>

void	*btree_search_item(t_btree *root, void *data_ref,
					int (*cmpf)(void *, void *))
{
	void	*returned_value;

	if (!root)
		return (NULL);
	returned_value = btree_search_item(root->left, data_ref, cmpf);
	if (returned_value)
		return (returned_value);
	if (cmpf(data_ref, root->item) == 0)
		return (root->item);
	returned_value = btree_search_item(root->right, data_ref, cmpf);
	if (returned_value)
		return (returned_value);
	return (NULL);
}
