#include <miniRT.h>

void	render(t_world *world, t_window *win)
{
	t_vect	crr_pix;
	t_ray	ray;
	t_vect	tmp;
	int		width;
	int		height;

	height = 0;
	while (height < world->image_height)
	{
		width = 0;
		while (width < world->image_width)
		{
			tmp = vect_scale(&world->delta_u, width);
			crr_pix = vect_add(&world->first_pixel, &tmp);
			tmp = vect_scale(&world->delta_v, height);
			crr_pix = vect_add(&crr_pix, &tmp);
			ray.origin = world->camera.center;
			ray.direction = crr_pix;
			win->(img_ptr + (height * world->image_width) + width) = calculate_pixel_color(&ray, win);
			width++;
		}
		height++;
	}
}