/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalende <ikalende@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:15:28 by ikalende          #+#    #+#             */
/*   Updated: 2024/03/14 17:15:28 by ikalende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vect	vect_scale(t_vect const *vect, double scalar)
{
	t_vect	tmp;

	tmp.x = vect->x * scalar;
	tmp.y = vect->y * scalar;
	tmp.z = vect->z * scalar;
	return (tmp);
}