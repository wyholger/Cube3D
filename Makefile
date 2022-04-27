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
				src/parser/make_map_is_rectangle.c\
				src/parser/validate_border.c\
				src/minimap/minimap.c\
				src/mlx/mlx.c\
				src/minimap/ray.c\
				src/minimap/rays.c\
				src/minimap/ray_util.c\
				src/minimap/draw_line.c\
				src/raycasting/raycasting.c\
				src/color_operation/color_operation.c\
				src/minimap/util.c\
				src/minimap/ray_2.c


HDR			=	include/cube3d.h

OBJS		= ${SRCS:.c=.o}

CC			= gcc

FLAGS		= -Wall -Wextra -Werror -g

RM			= rm -f

UNAME_S		:= $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
		MLX_FLAGS = -Llibft -lft
	else
		MLX_FLAGS = -Llibft -lft -lmlx -lm -Ofast -framework OpenGL -framework AppKit -lz
	endif

%.o : %.c $(HDR)
	gcc $(FLAGS) -c $< -o $@ -Ofast

all:	$(NAME)

$(NAME):	$(OBJS) Makefile
		make -C libft
		make -C minilibx
		$(CC) $(FLAGS) $(MLX_FLAGS) $(SRCS) libft/libft.a minilibx/libmlx.a -o $(NAME)

clean:
		${RM} ${OBJS}
		$(MAKE) clean -C ./libft
		$(MAKE) clean -C ./minilibx

fclean:		clean
		${RM} ${NAME}
		$(MAKE) fclean -C ./libft
		$(MAKE) clean -C ./minilibx

re:		fclean all clean