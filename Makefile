INC_DIR = inc/
LIBMLX_DIR = libmlx/
LIBFT_DIR = libft/
SRCS_DIR = src/
HEADS = minirt.h libft.h mlx.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)
LIBS = -lm -L$(LIBMLX_DIR) -lmlx -L$(LIBFT_DIR) -lft
RM = rm -f
FILES =	calc_first_pixel.c \
		calc_upper_left.c \
		make_world.c \
		rezalloc.c \
		set_ambient.c \
		set_camera.c \
		set_err.c \
		set_light.c \
		set_obj_cylinder.c \
		set_obj_plane.c \
		set_obj_sphere.c \
		set_objects.c \
		set_screen.c \
		set_viewport_vects.c \
		vect_add.c \
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

$(NAME) : $(LIBFT_DIR)libft.a $(LIBMLX_DIR)libmlx.dylib $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(LIBS) $(OBJS)

$(LIBFT_DIR)libft.a :
	$(MAKE) -C $(LIBFT_DIR)
	cp -p $(LIBFT_DIR)libft.h $(INC_DIR)

$(LIBMLX_DIR)libmlx.dylib :
	$(MAKE) -C $(LIBMLX_DIR)
	cp -p $(LIBMLX_DIR)mlx.h $(INC_DIR) && cp -p $(LIBMLX_DIR)libmlx.dylib ./

$(OBJS) : %.o : %.c $(addprefix $(INC_DIR),$(HEADS))
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(LIBMLX_DIR) clean
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(INC_DIR)libft.h $(INC_DIR)mlx.h
	$(RM) $(NAME) libmlx.dylib
	
re : fclean all