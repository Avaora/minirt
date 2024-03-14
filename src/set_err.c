/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalende <ikalende@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:14:08 by ikalende          #+#    #+#             */
/*   Updated: 2024/03/14 17:14:09 by ikalende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	set_err(const char *msg)
{
	if (errno != 0)
		perror(msg);
	else
	{
		if (msg == NULL)
			printf("Error\n");
		else
			printf("Error\n%s\n",msg);
	}
	exit(1);
}