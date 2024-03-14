#include <minirt.h>
#include <mlx.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{

	t_world	world;

	make_world(&world, &scene);
	/*scene.camera.center = {0, 0, 0};
	scene.camera.direction = {0, 0, 1};
	scene.camera.field_of_view = 70;
	
	scene.aspect_ratio = 16.0 / 9.0;
	scene.image_width = 512;
	scene.image_height = scene.image_width / scene.aspect_ratio;
	if (scene.image_height < 1)
		scene.image_height = 1;
	// this is the order of assigning don't change the order
	scene.viewport_height = 2.0;
	scene.viewport_width = scene.viewport_height * (double(scene.image_width) / scene.image_height);
	scene.viewport_u = {scene.viewport_width, 0, 0};
	scene.viewport_v = {0, -scene.viewport_height, 0};
	scene.camera.focal_length = (vect_len(scene.viewport_u) / 2) * tan((scene.camera.field_of_view / 2) * (M_PI / 180));
	scene.delta_u = vect_scale(&scene.viewport_u, ((double)1 / scene.image_width));
	scene.delta_v = vect_scale(&scene.viewport_v, ((double)1 / scene.image_height));

	calc_upper_left(&scene);*/
	return (0);
}
