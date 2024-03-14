#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <unistd.h>
# include <sys/errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <libft.h>

# define IMG_WIDTH 1280
# define IMG_HEIGHT 720
# define VIEWPORT_HEIGHT 2.0
# define BUF_SIZE 128
# define ERR_FILE "File error"

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

typedef struct	s_vect
{
	double		x;
	double		y;
	double		z;
}				t_vect;

typedef struct	s_ray
{
	t_vect		origin;
	t_vect		direction;
}				t_ray;

typedef struct	s_amb_light
{
	double		power;
	t_color		color;
}				t_amb_light;

typedef struct	s_camera
{
	t_vect		center;
	t_vect		direction;
	double		field_of_view;
	double		focal_length;
}				t_camera;

typedef struct	s_light
{
	t_vect		center;
	double		power;
	t_color		color;
}				t_light;

typedef struct	s_sphere
{
	t_vect		center;
	double		diameter;
	t_color		color;
}				t_sphere;

typedef struct	s_plane
{
	t_vect		center;
	t_vect		direction;
	t_color		color;
}				t_plane;

typedef struct	s_cylinder
{
	t_vect		center;
	t_vect		direction;
	double		diameter;
	double		height;
	t_color		color;
}				t_cylinder;

typedef struct	s_world
{
	t_amb_light	amb_light;
	t_camera	camera;
	t_light		light;
	int			image_width;
	int			image_height;
	double		viewport_width;
	double		viewport_height;
	t_vect		viewport_u;
	t_vect		viewport_v;
	t_vect		delta_u;
	t_vect		delta_v;
	t_vect		upper_left;
	t_vect		first_pixel;
	t_list		*objs;
}				t_world;

typedef struct	s_scene
{
	int			identifier;
	double		coord[3];
	unsigned char	rgb[3];
	double		amb_ligth;
	double		brightness;
	double		fov;
	double		dimater;
	double		height;
	double		vector[3];
}				t_scene;

enum	e_types
{
	AMBIENT = 1,
	CAMERA,
	LIGHT,
	PLANE,
	SPHERE,
	CYLINDER,
};

enum	e_types_abbv
{
	A = 1,
	C,
	L,
	pl,
	sp,
	cy,
};
void	calc_first_pixel(t_world *world);
void	calc_upper_left(t_world *world);
void	make_world(t_world *world, t_list const *scene);
void	*rezalloc(void *ptr, size_t c_size, size_t n_size);
void	set_ambient(t_world *world, t_scene const *scene);
void	set_camera(t_world *world, t_scene const *scene);
void	set_err(const char *msg);
void	set_light(t_world *world, t_scene const *scene);
void	set_obj_cylinder(t_world *world, t_scene const *scene);
void	set_obj_plane(t_world *world, t_scene const *scene);
void	set_obj_sphere(t_world *world, t_scene const *scene);
void	set_objects(t_world *world, t_list const *scene);
void	set_screen(t_world *world);
void	set_viewport_vects(t_world *world);
t_vect	vect_add(t_vect const *vect1, t_vect const *vect2);
double	vect_dot(t_vect const *vect1, t_vect const *vect2);
double	vect_len(t_vect const *vect);
t_vect	vect_scale(t_vect const *vect, double scalar);
t_vect	vect_sub(t_vect const *vect1, t_vect const *vect2);
t_vect	vect_unit(t_vect const *vect);
void	*zalloc(size_t size);
#endif