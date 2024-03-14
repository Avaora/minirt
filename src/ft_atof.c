/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bukaya <bukaya@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 00:13:33 by bukaya            #+#    #+#             */
/*   Updated: 2024/02/27 00:15:01 by bukaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
// it should also check INT_MAX INT_MIN
double	ft_atof(const char *str, int *is_all_digit)
{
	double	num;
	double	sign;
	double	exponent;

	sign = 1;
	exponent = 0;
	num = 0;
	if (*str == '-' || *str == '+')
		if (*(str++) == '-')
			sign = -1;
	while (ft_isdigit(*str))
		num = (num * 10) + (*(str++) - 48);
	if (*str == '.' && ++str)
		while (ft_isdigit(*str) && ++exponent)
			num += ((*(str++) - 48) / pow(10, exponent));
	if (*str != '\0')
		*is_all_digit = CONTAIN_NON_DIGIT;
	return (num * sign);
}
