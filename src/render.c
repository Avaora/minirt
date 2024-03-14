#include <miniRT.h>

void	render(t_world *world, t_window *win)
{
	t_vect	crr_pix;
	t_ray	ray;
	t_vect	tmp;
	int		width;
	int		height;

	(void)ray;
	height = 0;
	int bpp = 24;
	int	size_l = win->win_width;
	int endi = 0;
	char *ptr = mlx_get_data_addr(win->img_ptr, &bpp, &size_l, &endi);
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
			*((int*)ptr + (width + (height * world->image_width))) = calculate_pixel_color(&ray, world);
			width++;
		}
		height++;
	}
}