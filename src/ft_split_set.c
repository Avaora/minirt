/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bukaya <bukaya@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 00:09:40 by bukaya            #+#    #+#             */
/*   Updated: 2024/02/27 00:12:55 by bukaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

const char	*ft_isinset(const char *str, const char *set, size_t i)
{
	size_t	j;

	j = 0;
	while (str[i] != '\0' && j < ft_strlen(set))
	{
		if (str[i] == set[j])
			return (&str[i]);
		j++;
	}
	return (NULL);
}

size_t	ft_word_counter(const char *str, const char *set)
{
	size_t	i;
	size_t	wc;

	i = 0;
	wc = 0;
	while (str[i])
	{
		while (ft_isinset(str, set, i) != 0)
			i++;
		if (ft_isinset(str, set, i) == 0)
			wc++;
		while (str[i] && ft_isinset(str, set, i) == 0)
			i++;
	}
	return (wc);
}

char	**ft_split_set(const char *str, const char *set)
{
	size_t	i;
	size_t	j;
	char	**arr;

	j = 0;
	i = 0;
	arr = ft_calloc(ft_word_counter(str, set) + 1, sizeof(char *));
	while (str[i])
	{
		while (ft_isinset(str, set, i) != 0)
			i++;
		while (str[i + j] && ft_isinset(str, set, i + j) == 0)
			j++;
		if (j > 0)
		{
			*(arr++) = ft_substr(str, i, j);
			i += j;
			j = 0;
		}
	}
	return (arr - ft_word_counter(str, set) + 1);
}
