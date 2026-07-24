/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 21:05:28 by rlebaill          #+#    #+#             */
/*   Updated: 2026/07/24 21:15:08 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putline(int x, char charset[3]);

void	rush04(int x, int y)
{
	int	i;

	i = 0;
	if (x < 1 || y < 1)
		return ;
	while (i < y)
	{
		if (i == 0)
			ft_putline(x, "ABC");
		else if (i == y - 1)
			ft_putline(x, "CBA");
		else
			ft_putline(x, "B B");
		i++;
	}
}
