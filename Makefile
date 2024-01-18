IDIR = ./
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(IDIR)
LIBS = -lm -L$(LIBMLX_LOC) -lmlx -L$(LIBFT_LOC) -lft
RM = rm -f
SRCS_LOC = src
SRCS =	check_file.c \
		file_ops.c \
		open_file.c \
		read_to_mem.c \
		rezalloc.c \
		set_err.c \
		zalloc.c \
		main.c
OBJS = $(SRCS:.c=.o)
NAME = miniRT

all : $(NAME)
$(NAME) : $(SRCS_LOC)/%.o
	$(CC) -o $(NAME) $(CFLAGS) $^ -L$(LIB_FT_LOC) -l$(LIB_FT) -L$(LIB_MLX_LOC) -l$(LIB_MLX) -l$(LIB_MATH)
$(SRCS_LOC)/%.o : $(SRCS_LOC)/%.c
	$(CC) $(CFLAGS) $@ -c -o $^
$(OBJS) : $(SRCS)
	cd $(LIB_FT_LOC) && make
	cd $(LIB_MLX_LOC) && make && cp libmlx.dylib ..
	cd $(SRCS_LOC) && $(CC) $(CFLAGS) $(SRCS) -c
clean :
	cd $(LIB_FT_LOC) && make clean
	cd $(LIB_MLX_LOC) && make clean
	cd $(SRCS_LOC) && $(RM) $(OBJS)
fclean : clean
	cd $(LIB_FT_LOC) && make fclean
	$(RM) $(NAME) libmlx.dylib
re : fclean all
.PHONY : all clean fclean re