INC_DIR = inc/
LIBMLX_DIR = mlx/
LIBFT_DIR = libft/
SRCS_DIR = src/
LIBMLX = libmlx.dylib
LIBFT = libft.a
HEADS = minirt.h libft.h mlx.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)
LIBS = -lm -L$(LIBMLX_DIR) -lmlx -L$(LIBFT_DIR) -lft
RM = rm -f
FILES =	check_file.c \
		file_ops.c \
		main.c \
		open_file.c \
		read_to_mem.c \
		rezalloc.c \
		set_err.c \
		zalloc.c
SRCS = $(addprefix $(SRCS_DIR),$(FILES))
OBJS = $(patsubst %.c,%.o,$(SRCS))
NAME = miniRT

all : $(NAME)
$(NAME) : $(LIBFT_DIR)$(LIBFT) $(LIBMLX_DIR)$(LIBMLX) $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(LIBS) $(OBJS)
$(LIBFT_DIR)$(LIBFT) :
	cd $(LIBFT_DIR) && make && cp libft.h ../$(INC_DIR)
$(LIBMLX_DIR)$(LIBMLX) :
	cd $(LIBMLX_DIR) && make && cp mlx.h ../$(INC_DIR) && cp libmlx.dylib ..
$(OBJS) : %.o : %.c $(addprefix $(INC_DIR),$(HEADS))
	$(CC) $(CFLAGS) $< -c -o $@
clean :
	cd $(LIBFT_DIR) && make clean
	cd $(LIBMLX_DIR) && make clean
	$(RM) $(OBJS)
fclean : clean
	cd $(LIBFT_DIR) && make fclean
	$(RM) $(NAME) libmlx.dylib
re : fclean all
.PHONY : all clean fclean re