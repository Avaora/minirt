/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safecmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bukaya <bukaya@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 23:57:34 by bukaya            #+#    #+#             */
/*   Updated: 2024/02/27 00:07:25 by bukaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	ft_safecmp(const char *str1, const char *str2, size_t len)
{
	if (!str1 || !str2 || len == 0
		|| ft_strlen(str1) < len || ft_strlen(str2) < len)
		return (FAILURE);
	return (ft_strncmp(str1, str2, len));
}
