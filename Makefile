INC_DIR = inc/
LIBMLX_LOC = mlx/
LIBFT_LOC = libft/
SRCS_LOC = src/
LIBMLX = libmlx.dylib
LIBFT = libft.a
DEPS = minirt.h libft.h mlx.h
DEPS = $(patsubst %.h,$(INC_DIR)%.h,$(DEPS))
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)
LIBS = -lm -L$(LIBMLX_LOC) -lmlx -L$(LIBFT_LOC) -lft
RM = rm -f
SRCS =	check_file.c \
		file_ops.c \
		main.c \
		open_file.c \
		read_to_mem.c \
		rezalloc.c \
		set_err.c \
		zalloc.c 
SRCS = $(patsubst %.c,$(SRCS_LOC)%.c,$(SRCS))
OBJS = $(patsubst %.c,%.o,$(SRCS))
NAME = miniRT

all : $(NAME)
$(NAME) : $(LIBFT_LOC)$(LIBFT) $(LIBMLX_LOC)$(LIBMLX) $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(LIBS) $(OBJS)
$(LIBFT_LOC)$(LIBFT) :
	cd $(LIBFT_LOC) && make && cp libft.h ../$(INC_DIR)
$(LIBMLX_LOC)$(LIBMLX) :
	cd $(LIBMLX_LOC) && make && cp mlx.h ../$(INC_DIR) && cp libmlx.dylib ..
$(OBJS) : %.o : %.c $(DEPS)
	$(CC) $(CFLAGS) $< -c -o $@
clean :
	cd $(LIBFT_LOC) && make clean
	cd $(LIBMLX_LOC) && make clean
	$(RM) $(OBJS)
fclean : clean
	cd $(LIBFT_LOC) && make fclean
	$(RM) $(NAME) libmlx.dylib
re : fclean all
.PHONY : all clean fclean re