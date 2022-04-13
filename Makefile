NAME		=	cube3D

SRCS		=	src/main.c\
				src/parser/color_pars.c\
                src/parser/error.c\
                src/parser/exit.c\
                src/parser/free.c\
                src/parser/init_null_data.c\
                src/parser/malloc_crash_processing.c\
                src/parser/open_map.c\
                src/parser/read_map.c\
                src/parser/recording_map.c\
                src/parser/validate_map.c\
				src/parser/make_map_is_rectangle.c

HDR			=	include/cube3d.h

OBJS		= ${SRCS:.c=.o}

CC			= gcc

FLAGS		= -Wall -Wextra -Werror -g

RM			= rm -f

UNAME_S		:= $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
		MLX_FLAGS = -Llibft -lft
	else
		MLX_FLAGS = -Llibft -lft -lmlx -lm -Ofast -framework OpenGL -framework AppKit
	endif

%.o : %.c $(HDR)
	gcc $(FLAGS) -c $< -o $@ -Ofast

all:	$(NAME)

$(NAME):	$(OBJS) Makefile
		make -C libft
		$(CC) $(FLAGS) $(MLX_FLAGS) $(SRCS) libft/libft.a -o $(NAME)

clean:
		${RM} ${OBJS}
		$(MAKE) clean -C ./libft

fclean:		clean
		${RM} ${NAME}
		$(MAKE) fclean -C ./libft

re:		fclean all clean