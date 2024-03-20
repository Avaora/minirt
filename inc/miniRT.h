#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <unistd.h>
# include <sys/errno.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <libft.h>
# include <get_next_line.h>
# include <mlx.h>

/*-------------------DEFINITIONS-------------------*/
# define SPLIT_SET 			"\t\v\f\r\n ,"
/*-------------------VALUE-RANGE-------------------*/
# define RGB_MAX					255
# define RGB_MIN					0
# define VECTOR_MAX					1
# define VECTOR_MIN 				-1
# define BRIGHTNESS_MAX 			1.0f
# define BRIGHTNESS_MIN				0.0f
/*-------------------RETURN-MACROS-----------------*/
# define SUCCESS					0
# define FAILURE					1
# define OUT_OF_RANGE				1
# define CONTAIN_NON_DIGIT			256
# define ATOF_ERR					257
# define UNDEFINED_IDENTIFIER 		1
/*-------------------ERROR---MACROS----------------*/
# define FILE_ERR					"File cannot be open"
# define FILE_EXTENSION_ERR 		"Invalid file extension"
# define UNDEFINED_CHAR_ERR 		"Element info contains a character"
# define OUT_OF_RANGE_ERR			"Element info is out of range"
# define UNDEFINED_IDENTIFIER_ERR	"Invalid identifer"
# define NON_NUMERIC_ERR 			"Info contains non-numeric characters"
/*-------------------WORLD---MACROS----------------*/
# define IMG_WIDTH 600
# define IMG_HEIGHT 600
# define VIEWPORT_HEIGHT 2.0
# define T_MAX 2147483647
# define T_MIN -2147483648
/*------------------ENUM-DECLARATIONS--------------*/
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

enum	e_range
{
	e_vector = 1,
	e_fov,
	e_rgb,
	e_light,
};

enum	e_rgb
{
	r = 0,
	g,
	b,
};

enum	e_coord
{
	x = 0,
	y,
	z,
};

/*-----------TPYEDEF-STRUCT-DECLARATIONS-----------*/
typedef struct	s_scene
{
	int		identifier;
	double	coord[3];
	double	rgb[3];
	double	amb_light;
	double	brightness;
	double	fov;
	double	diameter;
	double	height;
	double	vector[3];
}				t_scene;

typedef struct	s_counter
{
	int	ambient;
	int	camera;
	int	light;
}				t_counter;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

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
	int			id;
	double		power;
	t_color		color;
}				t_amb_light;

typedef struct	s_camera
{
	int			id;
	t_vect		center;
	t_vect		direction;
	double		field_of_view;
	double		focal_length;
}				t_camera;

typedef struct	s_light
{
	int			id;
	t_vect		center;
	double		power;
	t_color		color;
}				t_light;

typedef struct	s_objs
{
	int			id;
	t_vect		center;
	t_vect		direction;
	double		diameter;
	double		height;
	t_color		color;
}				t_objs;

typedef struct	s_hit
{
	int			is_hit;
	t_vect		normal;
	t_vect		point;
	double		t;
}				t_hit;

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
	t_vect		vw_pixel;
	t_ray		ray;
	t_hit		hit;
	t_list		*objs;
}				t_world;

typedef struct	s_window
{
	char		*win_title;
	int			win_width;
	int			win_height;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*fbuf;
	int			img_x;
	int			img_y;
	int			bpp;
	int			bpl;
	int			endian;
}				t_window;

/*-------------FUNCTION-PROTOTYPES----------------*/
void	calc_first_pixel(t_world *world);
void	calc_nearest(t_world *world, double t, t_objs const *obj);
void	calc_vw_pixel_and_ray(t_world *world, t_window *win);
t_color	calc_pixel_color(t_world *world);
void	calc_ray_hit(t_world *world);
void	calc_upper_left(t_world *world);
t_vect	cast_ray(t_ray const *ray, double t);
void	fbuf_pixel_put(t_window *win, t_color *color);
int		ft_arrfree(char **arr);
size_t	ft_arrlen(char **arr);
int		ft_assign_element_values(t_list **list, char *line);
double	ft_atof_parser(const char *str);
double	ft_atof(const char *str, int *is_all_digit);
int		ft_check_element_count(t_scene *elements, char **info);
int		ft_check_path(const char *path);
int		ft_check_range(double val, int type);
int		ft_fill_ambient(t_scene *elements, char **info, int *i);
int		ft_fill_brightness(t_scene *elements, char **info, int *i);
int		ft_fill_coordinates(t_scene *elements, char **info, int *i);
int		ft_fill_diameter(t_scene *elements, char **info, int *i);
int		ft_fill_fov(t_scene *elements, char **info, int *i);
int		ft_fill_height(t_scene *elements, char **info, int *i);
int		ft_fill_identifier(t_scene *element, char **info, int *i);
int		ft_fill_rgb(t_scene *elements, char **info, int *i);
int		ft_fill_scene_struct(t_scene *element, char **info, int *i, int *err);
int		ft_fill_vector(t_scene *elements, char **info, int *i);
int		ft_mandatory_counter(t_list *list);
int		ft_parse_elements(t_list **list, char **argv);
int		ft_puterror(char *msg);
int		ft_readline(char **line, int fd);
int		ft_safecmp(const char *str1, const char *str2, size_t len);
const char	*ft_isinset(const char *str, const char *set, size_t i);
size_t	ft_word_counter(const char *str, const char *set);
char	**ft_split_set(const char *str, const char *set);
void	hit_cylinder(t_world *world, t_objs *cy);
void	hit_plane(t_world *world, t_objs *pl);
void	hit_sphere(t_world *world, t_objs *sp);
void	make_window(t_world *world, t_window *win);
void	make_world(t_world *world, t_list const *scene);
void	render(t_world *world, t_window *win);
void	*rezalloc(void *ptr, size_t c_size, size_t n_size);
void	set_ambient(t_world *world, t_scene const *scene);
void	set_camera(t_world *world, t_scene const *scene);
void	set_err(const char *msg);
void	set_hit_struct(t_world *world);
void	set_light(t_world *world, t_scene const *scene);
void	set_obj_cylinder(t_world *world, t_scene const *scene);
void	set_obj_plane(t_world *world, t_scene const *scene);
void	set_obj_sphere(t_world *world, t_scene const *scene);
void	set_objects(t_world *world, t_list const *scene);
t_vect	vect_add(t_vect const *vect1, t_vect const *vect2);
t_vect	vect_cross(t_vect const *vect1, t_vect const *vect2);
double	vect_dot(t_vect const *vect1, t_vect const *vect2);
double	vect_len(t_vect const *vect);
t_vect	vect_scale(t_vect const *vect, double scalar);
t_vect	vect_sub(t_vect const *vect1, t_vect const *vect2);
t_vect	vect_unit(t_vect const *vect);
void	*zalloc(size_t size);
#endif