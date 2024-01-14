CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIB_MATH = m
LIB_MLX = mlx
LIB_FT = ft
LIB_FT_LOC = ./libft/
LIB_MLX_LOC = ./mlx/
SRCS =	check_file.c \
		file_ops.c \
		main.c \
		open_file.c \
		set_err.c \
		zalloc.c 
OBJS = $(SRCS:.c=.o)
NAME = miniRT

all : $(NAME)
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIB_FT_LOC) -l$(LIB_FT) -L$(LIB_MLX_LOC) -l$(LIB_MLX) -l$(LIB_MATH) -o $(NAME)
$(OBJS) : $(SRCS)
	cd $(LIB_FT_LOC) && make
	cd $(LIB_MLX_LOC) && make && cp libmlx.dylib ..
	$(CC) $(CFLAGS) $(SRCS) -c
clean :
	cd $(LIB_FT_LOC) && make clean
	cd $(LIB_MLX_LOC) && make clean
	$(RM) $(OBJS)
fclean : clean
	cd $(LIB_FT_LOC) && make fclean
	$(RM) $(NAME) libmlx.dylib
re : fclean all
.PHONY : all clean fclean re