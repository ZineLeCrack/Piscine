/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 09:37:11 by event             #+#    #+#             */
/*   Updated: 2026/07/16 09:37:40 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isnumeric(char c)
{
	return ('0' <= c && c <= '9');
}

int	ft_str_is_numeric(char *str)
{
	if (!*str)
		return (1);
	return (ft_isnumeric(*str) && ft_str_is_numeric(str + 1));
}
