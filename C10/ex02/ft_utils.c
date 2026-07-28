/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlebaill <rlebaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 12:54:44 by romain            #+#    #+#             */
/*   Updated: 2026/07/28 09:44:14 by rlebaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_puterr(char *program_name, const char *filename)
{
	ft_putstr_fd(basename(program_name), STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(filename, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	ft_strcat_in(char **str_ptr, char buf[BUFFER_SIZE])
{
	char	*tmp;
	char	*str;
	int		i;
	int		j;

	if (!*str_ptr)
	{
		str = malloc(1);
		str[0] = '\0';
	}
	else
		str = *str_ptr;
	tmp = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(buf) + 1));
	i = -1;
	while (str[++i])
		tmp[i] = str[i];
	j = 0;
	while (buf[j])
		tmp[i++] = buf[j++];
	tmp[i] = '\0';
	*str_ptr = tmp;
	free(str);
}

void	ft_putlast(const char *str, ssize_t bytes)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (--bytes)
	{
		if (i == 0)
			break ;
		i--;
	}
	ft_putstr_fd(&str[i], STDOUT_FILENO);
}
