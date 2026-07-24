/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 17:51:18 by rlebaill          #+#    #+#             */
/*   Updated: 2026/07/24 21:14:51 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putline(int x, char charset[3]);

void	rush01(int x, int y)
{
	int	i;

	i = 0;
	if (x < 1 || y < 1)
		return ;
	while (i < y)
	{
		if (i == 0)
			ft_putline(x, "/*\\");
		else if (i == y - 1)
			ft_putline(x, "\\*/");
		else
			ft_putline(x, "* *");
		i++;
	}
}
