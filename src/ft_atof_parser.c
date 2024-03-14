/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bukaya <bukaya@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:52:55 by bukaya            #+#    #+#             */
/*   Updated: 2024/03/13 23:53:38 by bukaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

double	ft_atof_parser(const char *str)
{
	double	val;
	int		is_all_digit;

	is_all_digit = 0;
	val = ft_atof(str, &is_all_digit);
	if (is_all_digit)
		return (ft_puterror(NON_NUMERIC_ERR) + CONTAIN_NON_DIGIT);
	return (val);
}
