/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalende <ikalende@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:15:24 by ikalende          #+#    #+#             */
/*   Updated: 2024/03/14 17:15:24 by ikalende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

double	vect_len(t_vect const *vect)
{
	double	tmp;

	tmp = sqrt(vect_dot(vect, vect));
	return (tmp);
}