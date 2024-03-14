#include <miniRT.h>

void	set_screen(t_world *world)
{
	world->image_width = IMG_WIDTH;
	if (world->image_width < 1)
		world->image_width = 1;
	world->image_height = IMG_HEIGHT;
	if (world->image_height < 1)
		world->image_height = 1;
	world->viewport_height = VIEWPORT_HEIGHT;
	if (world->viewport_height < 1)
		world->viewport_height = 1;
	world->viewport_width = world->viewport_height
		* ((double)world->image_width / world->image_height);
	set_viewport_vects(world);
	world->camera.focal_length = (vect_len(world->viewport_u) / 2)
		* tan((world->camera.field_of_view / 2) * (M_PI / 180));
	calc_upper_left(world);
	calc_first_pixel(world);
}