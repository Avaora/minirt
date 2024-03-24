#include <miniRT.h>

void	set_vw_vectors(t_world *world)
{
	double	d;

	d = tan((world->camera.field_of_view / 2) * (M_PI / 180));
	world->viewport_width = 2.0 * world->camera.focal_length * d;
	world->viewport_height = world->viewport_width
		/ ((double)world->image_width / world->image_height);
	world->camera.w = vect_scale(&world->camera.direction
		,-world->camera.focal_length);
	world->camera.w = vect_unit(&world->camera.w);
	world->camera.u = vect_cross(&world->camera.relative_up, &world->camera.w);
	world->camera.u = vect_unit(&world->camera.u);
	world->camera.v = vect_cross(&world->camera.w, &world->camera.u);
	world->viewport_u = vect_scale(&world->camera.u, world->viewport_width);
	world->viewport_v = vect_scale(&world->camera.v, -world->viewport_height);
	world->delta_u = vect_scale(&world->viewport_u, (1.0 / world->image_width));
	world->delta_v = vect_scale(&world->viewport_v, (1.0 / world->image_height)); 
}