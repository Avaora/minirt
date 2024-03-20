INC_DIR = inc/
LIBMLX_DIR = libmlx/
LIBFT_DIR = libft/
SRCS_DIR = src/
HEADS = miniRT.h libft.h mlx.h get_next_line.h
CC = gcc
CFLAGS = -fsanitize=address -Wall -Wextra -Werror -I $(INC_DIR)
LIBS = -L $(LIBMLX_DIR) -lmlx -L $(LIBFT_DIR) -lft -lm -framework OpenGL -framework AppKit
RM = rm -f
FILES = calc_first_pixel.c \
		calc_nearest.c \
		calc_vw_pixel_and_ray.c \
		calc_pixel_color.c \
		calc_ray_hit.c \
		calc_upper_left.c \
		cast_ray.c \
		fbuf_pixel_put.c \
		ft_arrfree.c \
		ft_arrlen.c \
		ft_assign_element_values.c \
		ft_atof_parser.c \
		ft_atof.c \
		ft_check_element_count.c \
		ft_check_path.c \
		ft_check_range.c \
		ft_fill_ambient.c \
		ft_fill_brightness.c \
		ft_fill_coordinates.c \
		ft_fill_diameter.c \
		ft_fill_fov.c \
		ft_fill_height.c \
		ft_fill_identifier.c \
		ft_fill_rgb.c \
		ft_fill_scene_struct.c \
		ft_fill_vector.c \
		ft_mandatory_counter.c \
		ft_parse_elements.c \
		ft_puterror.c \
		ft_readline.c \
		ft_safecmp.c \
		ft_split_set.c \
		get_next_line_utils.c \
		get_next_line.c \
		hit_cylinder.c \
		hit_plane.c \
		hit_sphere.c \
		make_window.c \
		make_world.c \
		render.c \
		rezalloc.c \
		set_ambient.c \
		set_camera.c \
		set_err.c \
		set_hit_struct.c \
		set_light.c \
		set_obj_cylinder.c \
		set_obj_plane.c \
		set_obj_sphere.c \
		set_objects.c \
		vect_add.c \
		vect_cross.c \
		vect_dot.c \
		vect_len.c \
		vect_scale.c \
		vect_sub.c \
		vect_unit.c \
		zalloc.c \
		main.c
SRCS = $(addprefix $(SRCS_DIR),$(FILES))
OBJS = $(patsubst %.c,%.o,$(SRCS))
NAME = miniRT

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(LIBFT_DIR)libft.a $(LIBMLX_DIR)libmlx.a $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LIBS)

$(LIBFT_DIR)libft.a :
	$(MAKE) -C $(LIBFT_DIR) bonus
	cp -p $(LIBFT_DIR)libft.h $(INC_DIR)

$(LIBMLX_DIR)libmlx.a :
	$(MAKE) -C $(LIBMLX_DIR)
	cp -p $(LIBMLX_DIR)mlx.h $(INC_DIR) && cp -p $(LIBMLX_DIR)libmlx.a ./

$(OBJS) : %.o : %.c $(addprefix $(INC_DIR),$(HEADS))
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(LIBMLX_DIR) clean
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(INC_DIR)libft.h $(INC_DIR)mlx.h
	$(RM) $(NAME) libmlx.a
	
re : fclean all