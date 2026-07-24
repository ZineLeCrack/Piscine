/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 17:39:05 by rlebaill          #+#    #+#             */
/*   Updated: 2026/07/24 21:33:27 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	rush(int x, int y);

void	ft_putline(int x, char charset[3])
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
			ft_putchar(charset[0]);
		else if (i == x - 1)
			ft_putchar(charset[2]);
		else
			ft_putchar(charset[1]);
		i++;
	}
	ft_putchar('\n');
}

int	main(void)
{
	int	x;
	int	y;

	x = 0;
	while (x < 10)
	{
		y = 0;
		while (y < 10)
		{
			rush(x, y);
			y++;
		}
		x++;
	}
}
