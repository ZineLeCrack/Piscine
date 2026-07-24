/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 17:39:05 by rlebaill          #+#    #+#             */
/*   Updated: 2026/07/24 21:32:15 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	rush00(int x, int y);
void	rush01(int x, int y);
void	rush02(int x, int y);
void	rush03(int x, int y);
void	rush04(int x, int y);

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

void	ft_launch_rush(int n)
{
	static void	(*rushes[])(int, int)
		= {&rush00, &rush01, &rush02, &rush03, &rush04};
	int			x;
	int			y;

	if (!(0 <= n && n <= 4))
	{
		write(2, "Wrong argument.\n", 16);
		return ;
	}
	x = -2;
	while (x < 10)
	{
		y = -2;
		while (y < 10)
		{
			rushes[n](x, y);
			y++;
		}
		x++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		write(2, "Wrong number of arguments.\n", 27);
	else
	{
		if (argv[1][0] == '0' && argv[1][1] && !argv[1][2])
			ft_launch_rush(argv[1][1] - '0');
		else
			write(2, "Wrong argument.\n", 16);
	}
}
