IDIR = inc/
LIBMLX_LOC = mlx/
LIBFT_LOC = libft/
SRCS_LOC = src
LIBMLX = libmlx.dylib
LIBFT = libft.a
DEPS = minirt.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(IDIR)
LIBS = -lm -L$(LIBMLX_LOC) -lmlx -L$(LIBFT_LOC) -lft
RM = rm -f
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
$(NAME) : $(LIBFT_LOC)$(LIBFT) $(LIBMLX_LOC)$(LIBMLX) $(SRCS_LOC)/
	$(CC) -o $(NAME) $(CFLAGS) $(LIBS) $^
$(LIBFT_LOC)$(LIBFT) :
	cd $(LIBFT_LOC) && make && cp libft.h ../$(IDIR)
$(LIBMLX_LOC)$(LIBMLX) :
	cd $(LIBMLX_LOC) && make && cp mlx.h ../$(IDIR) && cp libmlx.dylib ..
$(SRCS_LOC)/%.o : $(SRCS_LOC)/%.c $(IDIR)$(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@
clean :
	cd $(LIBFT_LOC) && make clean
	cd $(LIBMLX_LOC) && make clean
	cd $(SRCS_LOC) && $(RM) $(OBJS)
fclean : clean
	cd $(LIBFT_LOC) && make fclean
	$(RM) $(NAME) libmlx.dylib
re : fclean all
.PHONY : all clean fclean re