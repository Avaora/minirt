/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_range.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bukaya <bukaya@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:54:03 by bukaya            #+#    #+#             */
/*   Updated: 2024/03/13 23:54:40 by bukaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	ft_check_range(double val, int type)
{
	if (type == e_vector && (val < -1.0 || val > 1.0))
		return (ft_puterror(OUT_OF_RANGE_ERR));
	if (type == e_fov && (val < 0.0 || val > 180.0))
		return (ft_puterror(OUT_OF_RANGE_ERR));
	if (type == e_rgb && (val < 0.0 || val > 255.0))
		return (ft_puterror(OUT_OF_RANGE_ERR));
	if (type == e_light && (val < -1.0 || val > 1.0))
		return (ft_puterror(OUT_OF_RANGE_ERR));
	return (SUCCESS);
}
