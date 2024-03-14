/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalende <ikalende@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:13:48 by ikalende          #+#    #+#             */
/*   Updated: 2024/03/14 17:13:49 by ikalende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	make_world(t_world *world, t_list const *scene)
{
	set_objects(world, scene);
	set_screen(world);
}