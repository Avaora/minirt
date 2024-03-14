/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bukaya <bukaya@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:10:58 by bukaya            #+#    #+#             */
/*   Updated: 2024/03/13 23:11:01 by bukaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <mlx.h>

int	main(int argc, char **argv)
{
	t_list	*scene_elements;
	t_scene	*current_element;

	scene_elements = NULL;
	if (argc != 2)
		return (ft_puterror("Invalid number of arguments"));
	if (ft_parse_elements(&scene_elements, argv) == FAILURE)
	{
		ft_lstclear(&scene_elements, free);
		exit(FAILURE);
	}
	while (scene_elements)
	{
		current_element = (t_scene *)scene_elements->content;
		printf("Identifier: %d\n", current_element->identifier);
		printf("Coordinates: %f, %f, %f\n", current_element->coord[0],
			current_element->coord[1], current_element->coord[2]);
		printf("RGB: %f, %f, %f\n", current_element->rgb[0],
			current_element->rgb[1], current_element->rgb[2]);
		printf("Ambient Light: %f\n", current_element->amb_light);
		printf("Brightness: %f\n", current_element->brightness);
		printf("FOV: %f\n", current_element->fov);
		printf("Diameter: %f\n", current_element->diameter);
		printf("Height: %f\n", current_element->height);
		printf("Vector: %f, %f, %f\n", current_element->vector[0],
			current_element->vector[1], current_element->vector[2]);
		printf("\n");
		scene_elements = scene_elements->next;
	}
	t_world	world;

	make_world(&world, scene_elements);
	ft_lstclear(&scene_elements, free);
	return (0);
}
