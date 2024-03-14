/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zalloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalende <ikalende@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:15:38 by ikalende          #+#    #+#             */
/*   Updated: 2024/03/14 17:15:39 by ikalende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	*zalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size + 1);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}