/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bukaya <bukaya@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 23:57:49 by bukaya            #+#    #+#             */
/*   Updated: 2024/02/27 00:19:00 by bukaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	ft_check_path(const char *path)
{
	size_t	len;

	while (ft_strchr(path, '/') != NULL)
		path = ft_strchr(path, '/');
	len = ft_strlen(path);
	if (len <= 3 || ft_safecmp(&path[len - 3], ".rt", 3))
		return (FAILURE);
	return (SUCCESS);
}
