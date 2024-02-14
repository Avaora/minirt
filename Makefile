INC_DIR = inc/
LIBMLX_DIR = libmlx/
LIBFT_DIR = libft/
SRCS_DIR = src/
HEADS = minirt.h libft.h mlx.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)
LIBS = -lm -L$(LIBMLX_DIR) -lmlx -L$(LIBFT_DIR) -lft
RM = rm -f
FILES =	check_path.c \
		lexer.c \
		file_ops.c \
		main.c \
		mem_ops.c \
		open_file.c \
		read_to_mem.c \
		rezalloc.c \
		set_err.c \
		zalloc.c
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