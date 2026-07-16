/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 18:10:04 by romain            #+#    #+#             */
/*   Updated: 2026/07/16 18:12:24 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	n;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	n = nb;
	i = 1;
	while (i < power)
	{
		n *= nb;
		i++;
	}
	return (n);
}
