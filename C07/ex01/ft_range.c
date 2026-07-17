/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 09:33:23 by romain            #+#    #+#             */
/*   Updated: 2026/07/17 09:49:30 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	len;
	int	*tab;

	if (min >= max)
		return (NULL);
	len = max - min;
	tab = malloc(len * sizeof(int));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < len)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}
