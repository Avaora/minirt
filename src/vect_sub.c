/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_sub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalende <ikalende@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:15:31 by ikalende          #+#    #+#             */
/*   Updated: 2024/03/14 17:15:32 by ikalende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vect	vect_sub(t_vect const *vect1, t_vect const *vect2)
{
	t_vect	tmp;

	tmp.x = vect1->x - vect2->x;
	tmp.y = vect1->y - vect2->y;
	tmp.z = vect1->z - vect2->z;
	return (tmp);
}