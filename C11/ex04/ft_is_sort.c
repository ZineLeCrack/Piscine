/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 18:07:15 by romain            #+#    #+#             */
/*   Updated: 2026/07/20 18:20:13 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_both(int a, int b)
{
	if (a < 0 && b < 0)
		return (1);
	if (a > 0 && b > 0)
		return (1);
	if (a == b)
		return (1);
	return (0);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 2;
	while (i < length)
	{
		if (!ft_both(f(tab[i - 2], tab[i - 1]), f(tab[i - 1], tab[i])))
			return (0);
		i++;
	}
	return (1);
}
