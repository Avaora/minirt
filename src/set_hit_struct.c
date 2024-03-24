#include <miniRT.h>

void	set_hit_struct(t_world *world)
{
	world->hit.is_hit = 0;
	world->hit.obj = NULL;
	world->hit.point.x = 0;
	world->hit.point.y = 0;
	world->hit.point.z = 0;
	world->hit.normal.x = 0;
	world->hit.normal.y = 0;
	world->hit.normal.z = 0;
	world->hit.t = 0;
}