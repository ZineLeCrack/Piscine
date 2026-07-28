/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 17:37:21 by romain            #+#    #+#             */
/*   Updated: 2026/07/28 10:06:32 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	main(int argc, char **argv)
{
	int	i;
	int	args;
	int	canonical;

	i = 1;
	args = 0;
	canonical = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			if (argv[i][1] && argv[i][1] == 'C')
				canonical = 1;
		}
		else
			args++;
		i++;
	}
	if (!args)
		return (ft_handle_stdin(argv[0], canonical));
	return (ft_handle_arguments(argc, argv, args, canonical));
}
