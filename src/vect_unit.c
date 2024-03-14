/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_unit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalende <ikalende@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:15:35 by ikalende          #+#    #+#             */
/*   Updated: 2024/03/14 17:15:36 by ikalende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vect	vect_unit(t_vect const *vect)
{
	t_vect	tmp;

	tmp = vect_scale(vect, 1.0 / vect_len(vect));
	return (tmp);
}