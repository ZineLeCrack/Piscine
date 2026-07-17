/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 14:24:53 by romain            #+#    #+#             */
/*   Updated: 2026/07/17 14:50:36 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_is_in(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 1;
	count = (str[0] && !ft_is_in(str[0], charset));
	while (str[i])
	{
		if (ft_is_in(str[i - 1], charset) && !ft_is_in(str[i], charset))
			count++;
		i++;
	}
	return (count);
}

char	*ft_get_next_word(char *str, char *charset)
{
	int		i;
	int		len;
	char	*word;

	len = 0;
	while (str[len] && !ft_is_in(str[len], charset))
		len++;
	word = malloc(sizeof(char) * (len + 1));
	i = 0;
	while (str[i] && !ft_is_in(str[i], charset))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**split;
	char	*word;

	split = malloc(sizeof(char *) * (ft_count_words(str, charset) + 1));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (42)
	{
		while (ft_is_in(str[i], charset))
			i++;
		if (!str[i])
			break ;
		word = ft_get_next_word(&str[i], charset);
		split[j++] = word;
		i += ft_strlen(word);
	}
	split[j] = NULL;
	return (split);
}
